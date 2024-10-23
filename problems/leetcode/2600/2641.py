# 2641. Cousins in Binary Tree II
# https://leetcode.com/problems/cousins-in-binary-tree-ii/description

from collections import defaultdict, deque
from typing import *

# 1. 노드를 순회하면서 자기 자식들의 합을 구한다. 이 합은 Depth별로 모두 합해둔다.
# 2. Depth별 합에서 자기 자식들의 합을 빼서, 자기 자식들의 값으로 만든다.

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def replaceValueInTree(self, root: Optional[TreeNode]) -> Optional[TreeNode]:
        depthToTotalSum = defaultdict(int)
        q = deque()
        if root:
            q.append((root, 0))

        while q:
            node, depth = q.popleft()
            depthToTotalSum[depth] += node.val

            for child in [node.left, node.right]:
                if child:
                    q.append((child, depth + 1))

        q.clear()
        if root:
            q.append((root, 0))
            root.val = 0

        while q:
            node, depth = q.popleft()

            childrenSum = (node.left.val if node.left else 0) + (node.right.val if node.right else 0)
            for child in [node.left, node.right]:
                if child:
                    child.val = depthToTotalSum[depth + 1] - childrenSum
                    q.append((child, depth + 1))

        return root

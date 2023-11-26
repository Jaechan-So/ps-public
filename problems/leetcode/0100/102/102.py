# 102. Binary Tree Level Order Traversal
# https://leetcode.com/problems/binary-tree-level-order-traversal/description/

from collections import deque
from typing import *


# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def levelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
        traversal = []

        q = deque()
        if root:
            q.append((root, 0))

        while len(q) > 0:
            node, level = q.popleft()

            while len(traversal) < level + 1:
                traversal.append([])

            traversal[level].append(node.val)

            if node.left:
                q.append((node.left, level + 1))
            if node.right:
                q.append((node.right, level + 1))

        return traversal

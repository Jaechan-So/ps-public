# 2583. Kth Largest Sum in a Binary Tree
# https://leetcode.com/problems/kth-largest-sum-in-a-binary-tree/description

from collections import defaultdict, deque
from typing import *

# 1. BFS를 이용해서 모든 Level의 합을 구한다.
# 2. 정렬한 뒤 k번째 값을 구한다.
# T(n), S(n)

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def kthLargestLevelSum(self, root: Optional[TreeNode], k: int) -> int:
        dq = deque() # (TreeNode, level)
        if root:
            dq.append((root, 1))
        sums = defaultdict(int)

        while dq:
            node, level = dq.popleft()
            sums[level] += node.val

            for nextNode in [node.left, node.right]:
                if nextNode:
                    dq.append((nextNode, level + 1))

        sumList = list(sorted(sums.values(), reverse=True))
        return sumList[k - 1] if len(sumList) > k - 1 else -1

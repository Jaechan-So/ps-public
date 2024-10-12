# 113. Path Sum II
# https://leetcode.com/problems/path-sum-ii/description/

from typing import *

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def pathSum(self, root: Optional[TreeNode], targetSum: int) -> List[List[int]]:
        result, currentPath = [], []
        self.traverse(root, targetSum, currentPath, 0, result)
        return result

    def traverse(self, node: Optional[TreeNode], targetSum: int, currentPath: List[int], currentSum: int, result: List[List[int]]) -> None:
        if not node:
            return

        currentPath.append(node.val)

        if not node.left and not node.right and targetSum == currentSum + node.val:
            result.append([n for n in currentPath])
            currentPath.pop()
            return

        for child in [node.left, node.right]:
            if child:
                self.traverse(child, targetSum, currentPath, currentSum + node.val, result)

        currentPath.pop()

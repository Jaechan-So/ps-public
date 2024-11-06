# 124. Binary Tree Maximum Path Sum
# https://leetcode.com/problems/binary-tree-maximum-path-sum/description/

# (재사용 가능한 최대 합, 재사용 불가능한 최대 합)을 반환하는 함수가 있다고 가정하면

from typing import *

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def maxPathSum(self, root: Optional[TreeNode]) -> int:
        return max(self.reusableAndNonReusableMaxPathSum(root))

    def reusableAndNonReusableMaxPathSum(self, node: Optional[TreeNode]) -> tuple[float, float]:
        if not node:
            return 0, float("-inf")

        reusableLeft, nonReusableLeft = self.reusableAndNonReusableMaxPathSum(node.left)
        reusableRight, nonReusableRight = self.reusableAndNonReusableMaxPathSum(node.right)

        reusable = max(
            node.val, node.val + reusableLeft,
            node.val + reusableRight
        )
        nonReusable = max(
            reusableLeft if node.left else float("-inf"),
            reusableRight if node.right else float("-inf"),
            node.val + reusableLeft + reusableRight if node.left and node.right else float("-inf"),
            nonReusableLeft,
            nonReusableRight
        )

        return reusable, nonReusable

# 1120. Maximum Average Subtree
# https://leetcode.com/problems/maximum-average-subtree/description/

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

from typing import *


class Solution:
    def sum_and_count_and_max_avg_subtree(
        self, node: Optional[TreeNode]
    ) -> (int, int, float):
        if not node:
            return 0, 0, 0

        left_sum, left_count, left_max_avg = self.sum_and_count_and_max_avg_subtree(
            node.left
        )
        right_sum, right_count, right_max_avg = self.sum_and_count_and_max_avg_subtree(
            node.right
        )
        this_sum, this_count = (
            left_sum + right_sum + node.val,
            left_count + right_count + 1,
        )

        return (
            this_sum,
            this_count,
            max(
                left_max_avg,
                right_max_avg,
                0 if this_count == 0 else this_sum / this_count,
            ),
        )

    def maximumAverageSubtree(self, root: Optional[TreeNode]) -> float:
        _, _, max_avg = self.sum_and_count_and_max_avg_subtree(root)
        return max_avg

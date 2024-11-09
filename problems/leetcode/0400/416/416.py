# 416. Partition Equal Subset Sum
# https://leetcode.com/problems/partition-equal-subset-sum/description/

# 1. Naive Solution
# 일단 합이 홀수이면 불가능
# Backtracking

# 2. Solution
# Knapsack Approach
# dp[i][j]: i번째 index에서 합이 j가 될 수 있는지
# dp[i][j] = dp[i - 1][j] || dp[i - 1][j - nums[i]]
# 합이 전체의 절반이 되면 됨.

from typing import *

class Solution:
    def canPartition(self, nums: List[int]) -> bool:
        n = len(nums)

        total = sum(nums)
        if total % 2 == 1:
            return False

        memo = [False for _ in range((total // 2) + 1)]
        memo[0] = True

        for i in range(n):
            newMemo = [prev for prev in memo]

            for j in range((total // 2) + 1):
                if j - nums[i] >= 0:
                    newMemo[j] |= memo[j - nums[i]]

            memo = newMemo

        return memo[total // 2]

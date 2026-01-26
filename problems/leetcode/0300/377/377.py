# 377. Combination Sum IV
# https://leetcode.com/problems/combination-sum-iv/

class Solution:
    def combinationSum4(self, nums: List[int], target: int) -> int:
        dp = dict()

        def getCombinationSum(t: int) -> int:
            if t in dp:
                return dp[t]

            dp[t] = 0

            for num in nums:
                if num == t:
                    dp[t] += 1
                elif num < t:
                    dp[t] += getCombinationSum(t - num)

            return dp[t]

        return getCombinationSum(target)

# 2270. Number of Ways to Split Array
# https://leetcode.com/problems/number-of-ways-to-split-array/description

from typing import *

class Solution:
    def waysToSplitArray(self, nums: List[int]) -> int:
        n, numSplits, currentSum, totalSum = len(nums), 0, 0, sum(nums)

        for i in range(0, n - 1):
            currentSum += nums[i]
            if currentSum >= totalSum - currentSum:
                numSplits += 1

        return numSplits

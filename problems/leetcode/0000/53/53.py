# 53. Maximum Subarray
# https://leetcode.com/problems/maximum-subarray/description/

from typing import *


class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        n = len(nums)
        globalMax = localMax = nums[0]

        for i in range(1, n):
            localMax = max(nums[i], nums[i] + localMax)
            globalMax = max(globalMax, localMax)

        return globalMax

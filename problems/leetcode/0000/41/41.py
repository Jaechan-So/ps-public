# 41. First Missing Positive
# https://leetcode.com/problems/first-missing-positive/

from typing import *

class Solution:
    def firstMissingPositive(self, nums: List[int]) -> int:
        n = len(nums)

        for i in range(n):
            while 0 < nums[i] <= n and nums[i] != i + 1 and nums[nums[i] - 1] != nums[i]:
                index = nums[i] - 1
                nums[i], nums[index] = nums[index], nums[i]

        for i, num in enumerate(nums):
            if i + 1 != num:
                return i + 1

        return len(nums) + 1

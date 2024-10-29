# 3229. Minimum Operations to Make Array Equal to Target
# https://leetcode.com/problems/minimum-operations-to-make-array-equal-to-target/description/

from typing import *

class Solution:
    def minimumOperations(self, nums: List[int], target: List[int]) -> int:
        n = len(nums)

        operations = abs(target[0] - nums[0])
        for i in range(1, n):
            if (target[i] - nums[i] > 0 and target[i - 1] - nums[i - 1] > 0) or (target[i] - nums[i] < 0 and target[i - 1] - nums[i - 1] < 0):
                operations += max(0, abs(target[i] - nums[i]) - abs(target[i - 1] - nums[i - 1]))
            else:
                operations += abs((target[i] - nums[i]))

        return operations

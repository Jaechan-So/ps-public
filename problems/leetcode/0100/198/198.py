# 198. House Robber
# https://leetcode.com/problems/house-robber/description/

from typing import *

class Solution:
    def rob(self, nums: List[int]) -> int:
        max1, max2 = 0, 0

        for i, num in enumerate(nums):
            currentMax = max(max1 + num, max2)
            max1 = max2
            max2 = currentMax

        return max2

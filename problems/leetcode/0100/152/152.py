# 152. Maximum Product Subarray
# https://leetcode.com/problems/maximum-product-subarray/description/

from typing import *

class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        mini, maxi, totalMaxi = nums[0], nums[0], nums[0]

        for num in nums[1:]:
            if num > 0:
                mini, maxi = min(num, mini * num), max(num, maxi * num)
            else:
                mini, maxi = min(num, maxi * num), max(num, mini * num)
            totalMaxi = max(totalMaxi, maxi)

        return totalMaxi

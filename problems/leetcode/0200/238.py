# 238. Product of Array Except Self
# https://leetcode.com/problems/product-of-array-except-self/description/

from typing import *

class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        products = [1] * len(nums)

        product = 1
        for i in range(len(nums) - 1):
            product = product * nums[i]
            products[i + 1] *= product

        product = 1
        for i in range(len(nums) - 1, 0, -1):
            product = product * nums[i]
            products[i - 1] *= product

        return products

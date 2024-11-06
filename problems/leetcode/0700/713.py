# 713. Subarray Product Less Than K
# https://leetcode.com/problems/subarray-product-less-than-k/description/

from typing import *

class Solution:
    def numSubarrayProductLessThanK(self, nums: List[int], k: int) -> int:
        n = len(nums)
        left, right, total, subarrays = 0, 0, 1, 0

        while right < n:
            total *= nums[right]

            while left <= right and total >= k:
                total //= nums[left]
                left += 1

            subarrays += (right - left + 1)
            right += 1

        return subarrays

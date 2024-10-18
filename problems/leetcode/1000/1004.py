# 1004. Max Consecutive Ones III
# https://leetcode.com/problems/max-consecutive-ones-iii/description

from typing import *

# Sliding Window
# Window 안의 0 개수를 추적하면서 최대 Window 크기를 반환한다.

class Solution:
    def longestOnes(self, nums: List[int], k: int) -> int:
        n = len(nums)
        left, right = 0, 0

        zeros, maxWindow = 0, 0
        while right < n:
            zeros += (1 if nums[right] == 0 else 0)

            while left <= right and zeros > k:
                zeros -= (1 if nums[left] == 0 else 0)
                left += 1

            maxWindow = max(maxWindow, right - left + 1)
            right += 1

        return maxWindow

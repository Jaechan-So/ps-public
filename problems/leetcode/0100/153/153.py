# 153. Find Minimum in Rotated Sorted Array
# https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/description/

from typing import *

class Solution:
    def findMin(self, nums: List[int]) -> int:
        n = len(nums)
        left, right = 0, n - 1

        while left < right:
            mid = (left + right) // 2

            if nums[left] <= nums[mid] and nums[mid] > nums[right]:
                left = mid + 1
            elif nums[left] >= nums[mid] and nums[mid] < nums[right]:
                right = mid
            else:
                return nums[left]

        return nums[left]

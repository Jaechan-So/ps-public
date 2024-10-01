# 162. Find Peak Element
# https://leetcode.com/problems/find-peak-element/description

from typing import *

class Solution:
    def findPeakElement(self, nums: List[int]) -> int:
        n = len(nums)
        start, end = 0, n - 1

        while start < end:
            mid = (start + end) // 2
            left, right = self.isBiggerThanLeft(nums, mid), self.isBiggerThanRight(nums, mid)

            if left and right:
                return mid
            elif left:
                start = mid + 1
            else:
                end = mid

        return start

    def isBiggerThanLeft(self, nums: List[int], index: int) -> bool:
        return index == 0 or nums[index - 1] < nums[index]

    def isBiggerThanRight(self, nums: List[int], index: int) -> bool:
        return index == len(nums) - 1 or nums[index] > nums[index + 1]

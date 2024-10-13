# 42. Trapping Rain Water
# https://leetcode.com/problems/trapping-rain-water/description/

from typing import *

class Solution:
    def trap(self, height: List[int]) -> int:
        n = len(height)
        left, leftPivot, right, rightPivot = 0, 0, n - 1, n - 1

        water = 0
        while left < right:
            if height[left] < height[right]:
                left += 1
                if height[leftPivot] < height[left]:
                    leftPivot = left
                water += (height[leftPivot] - height[left])
            else:
                right -= 1
                if height[rightPivot] < height[right]:
                    rightPivot = right
                water += (height[rightPivot] - height[right])

        return water

# 11. Container With Most Water
# https://leetcode.com/problems/container-with-most-water/description/

# Two Pointer
# 왼쪽, 오른쪽 중 작은 포인터를 계속 움직여서 최대 양을 갱신한다.

from typing import *

class Solution:
    def maxArea(self, height: List[int]) -> int:
        n = len(height)
        left, right = 0, n - 1
        area = 0

        while left < right:
            area = max(area, (right - left) * min(height[left], height[right]))

            if height[left] < height[right]:
                left += 1
            else:
                right -= 1

        return area

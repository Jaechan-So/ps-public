# 84. Largest Rectangle in Histogram
# https://leetcode.com/problems/largest-rectangle-in-histogram/description/

from typing import *

# Monotonically Increasing Stack을 유지했을 때,
# 1. 더 큰 수가 들어왔을 때 - 그냥 push한다
# 2. 더 작은 수가 들어와서 기존 수를 빼야할 때 - 그 전 Index와 추가되는 수의 Index가 양 끝, 높이는 빼야 하는 수가 됨
# 3. 최종 상태의 Motonically Increasing Stack - 그 전 Index와 오른쪽 끝 Index가 양 끝

class Solution:
    def largestRectangleArea(self, heights: List[int]) -> int:
        n = len(heights)
        mono = [(0, -1)] # (height, index)

        maxArea = 0
        for i, height in enumerate(heights):
            while len(mono) > 1 and mono[-1][0] > height:
                maxArea = max(maxArea, (i - mono[-2][1] - 1) * mono[-1][0])
                mono.pop()
            mono.append((height, i))

        for i in range(1, len(mono)):
            maxArea = max(maxArea, (n - mono[i - 1][1] - 1) * mono[i][0])

        return maxArea

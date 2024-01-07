# 1870. Minimum Speed to Arrive on Time
# https://leetcode.com/problems/minimum-speed-to-arrive-on-time/description/

from math import *
from typing import *


class Solution:
    def minSpeedOnTime(self, dist: List[int], hour: float) -> int:
        n = len(dist)
        if n - 1 + 0.01 > hour:
            return -1

        start, end = 1, max(dist) * 100 + 1

        def getTotalTime(speed):
            t = 0

            for i in range(n - 1):
                t += ceil(dist[i] / speed)
            t += dist[n - 1] / speed

            return t

        while start < end:
            mid = (start + end) // 2
            total = getTotalTime(mid)

            if total <= hour:
                end = mid
            else:
                start = mid + 1

        return int(end)

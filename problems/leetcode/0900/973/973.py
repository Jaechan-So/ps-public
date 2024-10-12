# 973. K Closest Points to Origin
# https://leetcode.com/problems/k-closest-points-to-origin/description/

from collections import heapq
from typing import *

class Solution:
    def kClosest(self, points: List[List[int]], k: int) -> List[List[int]]:
        closestPoints = [] # heapq - (square distance, x, y)

        for x, y in points:
            heapq.heappush(closestPoints, (-(x ** 2 + y ** 2), x, y))
            if len(closestPoints) > k:
                heapq.heappop(closestPoints)

        return [[x, y] for _, x, y in closestPoints]

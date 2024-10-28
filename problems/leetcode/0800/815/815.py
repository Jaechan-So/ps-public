# 815. Bus Routes
# https://leetcode.com/problems/bus-routes/description/

from collections import defaultdict, deque
from typing import *

class Solution:
    def numBusesToDestination(self, routes: List[List[int]], source: int, target: int) -> int:
        stopNumToRouteIndices = defaultdict(list[int])
        for i, route in enumerate(routes):
            for stop in route:
                stopNumToRouteIndices[stop].append(i)

        q = deque()
        q.append((source, 0))

        visitedStopNums, visitedRouteIndices = set(), set()
        visitedStopNums.add(source)
        while q:
            stopNum, move = q.popleft()

            if stopNum == target:
                return move

            for routeIndex in stopNumToRouteIndices[stopNum]:
                if routeIndex in visitedRouteIndices:
                    continue

                visitedRouteIndices.add(routeIndex)
                for nextStopNum in routes[routeIndex]:
                    if nextStopNum in visitedStopNums:
                        continue

                    visitedStopNums.add(nextStopNum)
                    q.append((nextStopNum, move + 1))

        return -1

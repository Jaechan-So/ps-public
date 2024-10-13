# 218. The Skyline Problem
# https://leetcode.com/problems/the-skyline-problem

from collections import heapq
from typing import *

# 1. 빌딩 추가
# 최고 높이인 경우, key point에 추가
# 현재 지나는 중인 빌딩에 추가

# 2. 빌딩 종료
# 현재 지나는 중인 빌딩에서 제거
# 최고 높이인 경우, 현재 지나는 중인 빌딩 중 다음으로 높은 높이를 key point에 추가
# 아무 빌딩이 없을 경우, 지면을 추가

# (높이, 마지막 점) Priority Queue
# building을 순회하면서 더 이른 쪽 먼저
# 마지막 점이 현재 x좌표보다 더 이른 경우는 빼줘야 함

class Solution:
    def getSkyline(self, buildings: List[List[int]]) -> List[List[int]]:
        keyPoints = []
        coordinates = set([building[0] for building in buildings] + [building[1] for building in buildings])

        # heapq (-height, end)
        currentBuildings = []
        index = 0

        for x in sorted(list(coordinates)):
            # Add buildings
            previousTop = -currentBuildings[0][0] if len(currentBuildings) > 0 else 0
            added = False
            while index < len(buildings) and buildings[index][0] == x:
                added = True
                l, r, h = buildings[index]
                heapq.heappush(currentBuildings, (-h, r))
                index += 1
            if added and previousTop < -currentBuildings[0][0]:
                keyPoints.append((x, -currentBuildings[0][0]))

            # Cleanup buildings
            if len(currentBuildings) > 0 and currentBuildings[0][1] == x:
                h = -currentBuildings[0][0]
                while len(currentBuildings) > 0 and currentBuildings[0][1] <= x:
                    heapq.heappop(currentBuildings)
                if len(currentBuildings) == 0:
                    keyPoints.append((x, 0))
                elif -currentBuildings[0][0] < h:
                    keyPoints.append((x, -currentBuildings[0][0]))

        return keyPoints

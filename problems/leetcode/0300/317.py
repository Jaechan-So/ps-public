# 317. Shortest Distance from All Buildings
# https://leetcode.com/problems/shortest-distance-from-all-buildings/description

# 모든 1에서 시작해서 거리를 음수로 계속 더하면서 진행.
# 완전 탐색의 경우, 50^4 정도의 시간 복잡도가 필요함.

# m, n - Size of the grid
# distanceTotal - Sum of distances
# traversalQueue(x, y, dist), visited - For each loop

from collections import deque
from typing import *

class Solution:
    def __init__(self):
        self.dx = [1, -1, 0, 0]
        self.dy = [0, 0, 1, -1]

    def shortestDistance(self, grid: List[List[int]]) -> int:
        m, n = len(grid), len(grid[0])

        def isValidCoordinate(r: int, c: int) -> bool:
            return 0 <= r < m and 0 <= c < n
        def isBuilding(r: int, c: int) -> bool:
            return grid[r][c] == 1
        def isEmptyLand(r: int, c: int) -> bool:
            return grid[r][c] == 0

        distanceTotal = [[0 if isEmptyLand(i, j) else int(1e7) for j in range(n)] for i in range(m)]
        arriveCount = [[0 if isEmptyLand(i, j) else -1 for j in range(n)] for i in range(m)]
        totalBuildingCount = sum([sum([1 if isBuilding(i, j) else 0 for j in range(n)]) for i in range(m)])

        for i in range(m):
            for j in range(n):
                if not isBuilding(i, j):
                    continue

                traversalQueue = deque()
                visited = set()

                traversalQueue.append((i, j, 0))
                visited.add((i, j))

                while len(traversalQueue) > 0:
                    r, c, dist = traversalQueue.popleft()
                    if isEmptyLand(r, c):
                        distanceTotal[r][c] += dist
                        arriveCount[r][c] += 1

                    for k in range(4):
                        newR, newC = r + self.dx[k], c + self.dy[k]
                        if isValidCoordinate(newR, newC) and isEmptyLand(newR, newC) and (newR, newC) not in visited:
                            traversalQueue.append((newR, newC, dist + 1))
                            visited.add((newR, newC))

        totalMin = int(1e7)
        for i in range(m):
            for j in range(n):
                if arriveCount[i][j] == totalBuildingCount:
                    totalMin = min(totalMin, distanceTotal[i][j])
        return totalMin if totalMin != 1e7 else -1

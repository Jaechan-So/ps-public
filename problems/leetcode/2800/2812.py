# 2812. Find the Safest Path in a Grid
# https://leetcode.com/problems/find-the-safest-path-in-a-grid/description

import heapq
from typing import *

# 1. 각 칸에서의 Safeness Factor를 구할 수 있다. 단순한 방법으로는 O(n^4)의 시간 복잡도를 가진다. BFS를 이용하면, O(n^2)에 가능하다.
# 2. 시작점에서 출발해서 BFS로 계속 탐색한다. 특정 칸에 도달했을 때, 현재까지의 path에서 거쳐온 값들의 최솟값과 도달한 칸의 값의 최솟값을 비교한다.

class Solution:
    def __init__(self):
        self.delta = [(1, 0), (-1, 0), (0, 1), (0, -1)]

    def maximumSafenessFactor(self, grid: List[List[int]]) -> int:
        n = len(grid)
        cellSafeness = [[float("inf") for _ in range(n)] for _ in range(n)]

        q = []
        for i, row in enumerate(grid):
            for j, cell in enumerate(row):
                if cell == 1:
                    heapq.heappush(q, (0, i, j))
                    cellSafeness[i][j] = 0

        while len(q) > 0:
            factor, r, c = heapq.heappop(q)

            for dr, dc in self.delta:
                nextR, nextC = r + dr, c + dc

                if 0 <= nextR < n and 0 <= nextC < n and factor + 1 < cellSafeness[nextR][nextC]:
                    cellSafeness[nextR][nextC] = factor + 1
                    heapq.heappush(q, (cellSafeness[nextR][nextC], nextR, nextC))

        pathSafeness = [[float("-inf") for _ in range(n)] for _ in range(n)]
        pathSafeness[0][0] = cellSafeness[0][0]

        traversal = []
        heapq.heappush(traversal, (-cellSafeness[0][0], 0, 0))

        while len(traversal) > 0:
            factor, r, c = heapq.heappop(traversal)
            factor = -factor

            for dr, dc in self.delta:
                nextR, nextC = r + dr, c + dc

                if 0 <= nextR < n and 0 <= nextC < n and min(factor, cellSafeness[nextR][nextC]) > pathSafeness[nextR][nextC]:
                    pathSafeness[nextR][nextC] = min(factor, cellSafeness[nextR][nextC])
                    heapq.heappush(traversal, (-pathSafeness[nextR][nextC], nextR, nextC))

        return pathSafeness[n - 1][n - 1]

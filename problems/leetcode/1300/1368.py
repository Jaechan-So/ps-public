# 1368. Minimum Cost to Make at Least One Valid Path in a Grid
# https://leetcode.com/problems/minimum-cost-to-make-at-least-one-valid-path-in-a-grid/description

from collections import heapq
from typing import *

# BFS + 최소값

class Solution:
    def minCost(self, grid: List[List[int]]) -> int:
        dr = [0, 0, 0, 1, -1]
        dc = [0, 1, -1, 0, 0]

        m, n = len(grid), len(grid[0])
        costs = [[float("inf") for _ in range(n)] for _ in range(m)]
        costs[0][0] = 0

        dists = [] # (cost, r, c)
        heapq.heappush(dists, (0, 0, 0))

        while len(dists) > 0:
            cost, r, c = heapq.heappop(dists)

            if r == m - 1 and c == n - 1:
                return cost

            for i in range(1, 5):
                nextR, nextC = r + dr[i], c + dc[i]

                signCost = 0 if i == grid[r][c] else 1
                if 0 <= nextR < m and 0 <= nextC < n and signCost + cost < costs[nextR][nextC]:
                    costs[nextR][nextC] = signCost + cost
                    heapq.heappush(dists, (costs[nextR][nextC], nextR, nextC))

        # Unreachable
        return costs[m - 1][n - 1]

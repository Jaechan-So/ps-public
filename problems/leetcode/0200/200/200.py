# 200. Number of Islands
# https://leetcode.com/problems/number-of-islands/description

from collections import deque
from typing import *

class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        m, n = len(grid), len(grid[0])
        visited = set()
        islands = 0

        for i in range(m):
            for j in range(n):
                if grid[i][j] == "1" and (i, j) not in visited:
                    islands += 1

                    q = deque()
                    q.append((i, j))
                    visited.add((i, j))

                    while q:
                        r, c = q.popleft()

                        for dr, dc in [(1, 0), (-1, 0), (0, 1), (0, -1)]:
                            nextR, nextC = r + dr, c + dc
                            if 0 <= nextR < m and 0 <= nextC < n and grid[nextR][nextC] == "1" and (nextR, nextC) not in visited:
                                visited.add((nextR, nextC))
                                q.append((nextR, nextC))

        return islands

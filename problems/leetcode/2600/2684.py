# 2684. Maximum Number of Moves in a Grid
# https://leetcode.com/problems/maximum-number-of-moves-in-a-grid/description

from typing import *

# DFS + DP
# Space Optimization도 가능

class Solution:
    def maxMoves(self, grid: List[List[int]]) -> int:
        m, n = len(grid), len(grid[0])
        memo = [[-1 for i in range(n)] for _ in range(m)]

        maxMoveCount = 0
        for i in range(m):
            maxMoveCount = max(maxMoveCount, self.traverse(grid, memo, m, n, i, 0))

        return maxMoveCount

    def traverse(self, grid: List[List[int]], memo: List[List[int]], m: int, n: int, r: int, c: int) -> int:
        if memo[r][c] != -1:
            return memo[r][c]

        maxMoveCount = 0
        for dr in [-1, 0, 1]:
            nextR, nextC = r + dr, c + 1
            if 0 <= nextR < m and 0 <= nextC < n and grid[r][c] < grid[nextR][nextC]:
                maxMoveCount = max(maxMoveCount, 1 + self.traverse(grid, memo, m, n, nextR, nextC))

        memo[r][c] = maxMoveCount
        return memo[r][c]

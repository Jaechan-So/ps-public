# 417. Pacific Atlantic Water Flow
# https://leetcode.com/problems/pacific-atlantic-water-flow/

# 1. Naive Solution
# Pacific Ocean에 대해서 BFS, Atlantic Ocean에 대해서 BFS 2번 돌고, 겹치는 부분을 정답으로 반환
# T(mn), S(mn)

from collections import deque
from typing import *

class Solution:
    def pacificAtlantic(self, heights: List[List[int]]) -> List[List[int]]:
        m, n = len(heights), len(heights[0])

        pacific = set()
        for i in range(n):
            pacific.add((0, i))
        for i in range(m):
            pacific.add((i, 0))
        self.bfs(heights, pacific)

        atlantic = set()
        for i in range(m):
            atlantic.add((i, n - 1))
        for i in range(n):
            atlantic.add((m - 1, i))
        self.bfs(heights, atlantic)

        print(pacific)
        print(atlantic)

        return list(pacific.intersection(atlantic))

    def bfs(self, heights: List[List[int]], visited: set[tuple[int]]) -> None:
        m, n = len(heights), len(heights[0])
        q = deque(visited)

        while q:
            r, c = q.popleft()

            for dr, dc in [(1, 0), (-1, 0), (0, 1), (0, -1)]:
                nextR, nextC = r + dr, c + dc
                if 0 <= nextR < m and 0 <= nextC < n and heights[nextR][nextC] >= heights[r][c] and (nextR, nextC) not in visited:
                    visited.add((nextR, nextC))
                    q.append((nextR, nextC))

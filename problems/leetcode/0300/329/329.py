# 329. Longest Increasing Path in a Matrix
# https://leetcode.com/problems/longest-increasing-path-in-a-matrix/description/

from typing import *

# 각 칸에 대해서 DFS를 이용해서, 인접한 4칸 중 현재 칸보다 큰 칸에서 시작되는 longest increasing path의 길이 + 1 값들을 조사해서
# 그들 중 최댓값이 현재 칸의 longest increasing path의 길이이다.
# 한 개의 칸을 여러 번 지나쳐서 불필요한 계산을 방지하는 것을 위해서, 배열을 이용해서 memoization을 한다.

class Solution:
    def longestIncreasingPath(self, matrix: List[List[int]]) -> int:
        m, n = len(matrix), len(matrix[0])
        self.memo = [[-1 for _ in range(n)] for _ in range(m)]

        maxLen = 1

        for r in range(m):
            for c in range(n):
                maxLen = max(maxLen, self.getLongestIncreasingPathLength(matrix, m, n, r, c))

        return maxLen

    def getLongestIncreasingPathLength(self, matrix: List[List[int]], m: int, n: int, r: int, c: int) -> int:
        if self.memo[r][c] != -1:
            return self.memo[r][c]

        maxLen = 1

        for dr, dc in [(1, 0), (-1, 0), (0, 1), (0, -1)]:
            nextR, nextC = r + dr, c + dc
            if 0 <= nextR < m and 0 <= nextC < n and matrix[r][c] < matrix[nextR][nextC]:
                maxLen = max(maxLen, self.getLongestIncreasingPathLength(matrix, m, n, nextR, nextC) + 1)

        self.memo[r][c] = maxLen
        return self.memo[r][c]

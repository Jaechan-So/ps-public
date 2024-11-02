# 2435. Paths in Matrix Whose Sum Is Divisible by K
# https://leetcode.com/problems/paths-in-matrix-whose-sum-is-divisible-by-k/description

# Space Optimized DP
# memo[i][j]: grid[i][j]까지 도착했을 때, 각 나머지 별 path의 총 개수
# path를 합산하는 과정에서 T(k), 합산한 후에 현재 값을 보고 배열을 최대 T(k)번 shift 해야 함.
# T(mnk), S(nk)

from typing import *

class Solution:
    def numberOfPaths(self, grid: List[List[int]], k: int) -> int:
        mod = int(1e9 + 7)
        m, n = len(grid), len(grid[0])
        memo = [[0 for _ in range(k)] for _ in range(n + 1)]

        for i in range(m):
            newMemo = [[0 for _ in range(k)] for _ in range(n + 1)]

            for j in range(1, n + 1):
                shift = grid[i][j - 1] % k

                if i == 0 and j == 1:
                    newMemo[j][shift] = 1
                    continue

                newMemo[j] = [(memo[j][l] + newMemo[j - 1][l]) % mod for l in range(k)]
                newMemo[j] = newMemo[j][-shift:] + newMemo[j][:-shift]

            memo = newMemo

        return memo[n][0] % mod

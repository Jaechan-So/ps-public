# 1463. Cherry Pickup II
# https://leetcode.com/problems/cherry-pickup-ii/description

import itertools
from collections import defaultdict
from typing import *

# 1. 로봇이 1개일 때는, Backtracking + Memoization 방식으로 모든 경우의 수를 구할 수 있었다.
# 2. 로봇이 2개가 되었기 때문에 겹치는 곳에서 줍지 못한 체리에 의해서 최댓값을 단순하게 구할 수 없다.
# 3. 각 행에서의 상태는 70 * 69 = 4851가지가 존재하며, 이 때 각각의 최댓값은 구해둘 수 있다.

# 각 행에서의 상태를 (로봇 1의 위치, 로봇 2의 위치, 최대 체리 개수) 로 나타낼 수 있다. 최대 70^2 == 4900개
# 해당 상태에서 발생 가능한 새로운 시나리오는 4900 * 3 * 3 = 44100가지이고, 이를 바탕으로 다음 행의 각 상태별 최대 체리 개수를 구할 수 있다.
# T(m * n^2), S(n^2)

class Solution:

    def cherryPickup(self, grid: List[List[int]]) -> int:
        m, n = len(grid), len(grid[0])

        columnPairToMaxCherries = defaultdict(int) # ((Robot#1, Robot#2), max cherries)
        columnPairToMaxCherries[(0, n - 1)] = grid[0][0] + grid[0][n - 1]

        for r in range(1, m):
            nextColumnPairToMaxCherries = defaultdict(int)

            for (c1, c2), cherries in columnPairToMaxCherries.items():
                for dc1, dc2 in itertools.product([-1, 0, 1], repeat=2):
                    nextC1, nextC2 = min(c1 + dc1, c2 + dc2), max(c1 + dc1, c2 + dc2)

                    if 0 <= nextC1 < n and 0 <= nextC2 < n:
                        additionalCherries = grid[r][nextC1] + grid[r][nextC2] if nextC1 != nextC2 else grid[r][nextC1]
                        nextColumnPairToMaxCherries[(nextC1, nextC2)] = max(nextColumnPairToMaxCherries[(nextC1, nextC2)], cherries + additionalCherries)

            columnPairToMaxCherries = nextColumnPairToMaxCherries

        return max(columnPairToMaxCherries.values())

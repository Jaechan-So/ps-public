# 490. The Maze
# https://leetcode.com/problems/the-maze/description/

from collections import deque
from typing import *

# Approach 1. DFS / BFS + Memoization
# 방문 가능한 좌표를 모두 저장하면서, DFS / BFS를 시도한다.
# 특정 좌표에서 DFS / BFS를 할 때 가능한 좌표는 4가지 (상하좌우) 방향에서 가장 먼저 만나는 벽돌
# 이것을 미리 구해둘 수도 있음.
# 각 좌표를 순회하면서 만약 벽돌 좌표라면, 그 좌표에서 상하좌우로 가면서 벽돌을 만나기 전까지는 각 좌표에서 반대 방향으로 쭉 가면 벽돌 좌표까지만 가게 된다.
# 하지만 중복된 좌표 검사를 하기 때문에 굳이 미리 구해두지 않아도 좋을 것 같다.


class Solution:
    deltas = [(1, 0), (-1, 0), (0, 1), (0, -1)]

    def hasPath(
        self, maze: List[List[int]], start: List[int], destination: List[int]
    ) -> bool:
        m, n = len(maze), len(maze[0])

        def is_valid_coordinate(x: int, y: int) -> bool:
            return 0 <= x and x < m and 0 <= y and y < n

        visited = set()
        candidates = deque()

        candidates.append((start[0], start[1]))

        while len(candidates) > 0:
            r, c = candidates.popleft()
            if r == destination[0] and c == destination[1]:
                return True

            visited.add((r, c))

            for delta in self.deltas:
                rn, cn = r, c

                while is_valid_coordinate(rn, cn) and maze[rn][cn] != 1:
                    rn += delta[0]
                    cn += delta[1]
                rn -= delta[0]
                cn -= delta[1]

                if (rn, cn) not in visited:
                    candidates.append((rn, cn))

        return False

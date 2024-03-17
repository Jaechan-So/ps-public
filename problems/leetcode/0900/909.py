# 909. Snakes and Ladders
# https://leetcode.com/problems/snakes-and-ladders/description/

from collections import deque
from typing import *


class Solution:
    def snakesAndLadders(self, board: List[List[int]]) -> int:
        n = len(board)

        dist = [-1 for _ in range((n**2) + 1)]

        q = deque()
        q.append((1, 0))

        while len(q) > 0:
            index, currDist = q.popleft()

            if dist[index] != -1 and currDist >= dist[index]:
                continue

            dist[index] = currDist

            for j in range(index + 1, min(index + 6, n**2) + 1):
                quotient, remainder = (j - 1) // n, (j - 1) % n
                r = (n - 1) - quotient
                c = remainder if quotient % 2 == 0 else (n - 1) - remainder

                if board[r][c] != -1:
                    q.append((board[r][c], currDist + 1))
                else:
                    q.append((j, currDist + 1))

        return dist[n**2]

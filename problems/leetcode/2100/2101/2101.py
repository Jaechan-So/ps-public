# 2101. Detonate the Maximum Bombs
# https://leetcode.com/problems/detonate-the-maximum-bombs/description

from collections import deque
from typing import *

class Solution:
    def maximumDetonation(self, bombs: List[List[int]]) -> int:
        n = len(bombs)
        bombToNextBombs = dict()

        for i in range(n):
            bombToNextBombs[i] = [j for j in range(n) if self.isFirstBombAffectsSecondBomb(bombs[i], bombs[j])]

        maxBombs = 0
        for i in range(n):
            visited = set()
            visited.add(i)

            q = deque()
            q.append(i)

            while q:
                bomb = q.popleft()

                for nextBomb in bombToNextBombs[bomb]:
                    if nextBomb not in visited:
                        visited.add(nextBomb)
                        q.append(nextBomb)

            maxBombs = max(maxBombs, len(visited))

        return maxBombs

    def isFirstBombAffectsSecondBomb(self, bomb1: List[int], bomb2: List[int]) -> bool:
        x1, y1, r1 = bomb1
        x2, y2, _ = bomb2
        return (x1 - x2) ** 2 + (y1 - y2) ** 2 <= r1 ** 2

# 1197. Minimum Knight Moves
# https://leetcode.com/problems/minimum-knight-moves/description/

import heapq

# 값을 무조건 (x >= 0, y >= 0, y <= x, y >= -x) 를 만족하도록 바꿀 수 있음
# 이를 이용해서 고정된 구역으로 가져간 뒤, 범위 밖으로 나가면 계속 보정
# Priority Queue로 이동 횟수가 작은 것부터 고려하고, memoization으로 중복 연산 방지
# (이동 횟수, x좌표, y좌표)

class Solution:
    def minKnightMoves(self, x: int, y: int) -> int:
        memo = dict() # ((x좌표, y좌표), 최소 이동 횟수)
        directions = [(-2, -1), (-1, -2)]

        q = []
        startX, startY = self.interpolateCoordinate(x, y)
        heapq.heappush(q, (0, startX, startY))
        memo[(startX, startY)] = 0

        while q:
            move, i, j = heapq.heappop(q)

            if i == 0 and j == 0:
                return move

            if i + j == 2:
                return move + 2

            for dr, dc in directions:
                nextR, nextC = self.interpolateCoordinate(i + dr, j + dc)
                if ((nextR, nextC) not in memo) or (move + 1 < memo[(nextR, nextC)]):
                    heapq.heappush(q, (move + 1, nextR, nextC))
                    memo[(nextR, nextC)] = move + 1

    def interpolateCoordinate(self, x: int, y: int) -> tuple[int, int]:
        return max(abs(x), abs(y)), min(abs(x), abs(y))

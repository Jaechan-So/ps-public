# 1033. Moving Stones Until Consecutive
# https://leetcode.com/problems/moving-stones-until-consecutive/description

class Solution:
    def numMovesStones(self, a: int, b: int, c: int) -> List[int]:
        a, b, c = sorted([a, b, c])

        minMove = 0 if b - a == 1 and c - b == 1 else 1 if b - a <= 2 or c - b <= 2 else 2
        maxMove = c - a - 2

        return [minMove, maxMove]

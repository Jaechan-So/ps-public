# 2139. Minimum Moves to Reach Target Score
# https://leetcode.com/problems/minimum-moves-to-reach-target-score/


class Solution:
    def minMoves(self, target: int, maxDoubles: int) -> int:
        move, current, doubles = 0, target, maxDoubles

        while current > 1:
            if doubles == 0:
                return move + current - 1
            if current % 2 == 0 and doubles > 0:
                current //= 2
                doubles -= 1
            else:
                current -= 1
            move += 1

        return move

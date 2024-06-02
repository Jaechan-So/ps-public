# 2214. Minimum Health to Beat Game
# https://leetcode.com/problems/minimum-health-to-beat-game/description/

from typing import *


class Solution:
    def minimumHealth(self, damage: List[int], armor: int) -> int:
        return 1 + sum(damage) - max(damage) + max(0, max(damage) - armor)

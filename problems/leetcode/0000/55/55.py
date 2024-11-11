# 55. Jump Game
# https://leetcode.com/problems/jump-game/description/

# BFS + Hash Set
# Local Maximum

from typing import *

class Solution:
    def canJump(self, nums: List[int]) -> bool:
        maxIndex = 0

        for i, num in enumerate(nums):
            if maxIndex < i:
                return False
            maxIndex = max(maxIndex, i + num)

        return True

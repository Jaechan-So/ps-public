# 128. Longest Consecutive Sequence
# https://leetcode.com/problems/longest-consecutive-sequence/description/

from typing import *

class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        self.maxLens = dict({ num: -1 for num in nums })

        for num in nums:
            self.traverse(num)

        return max(self.maxLens.values()) if len(nums) > 0 else 0

    def traverse(self, num: int) -> int:
        if num not in self.maxLens:
            return 0

        if num in self.maxLens and self.maxLens[num] != -1:
            return self.maxLens[num]

        self.maxLens[num] = 1 + self.traverse(num - 1)
        return self.maxLens[num]

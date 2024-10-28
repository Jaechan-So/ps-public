# 2501. Longest Square Streak in an Array
# https://leetcode.com/problems/longest-square-streak-in-an-array/description

from typing import *

# (num, longestLength) Hash Map
# DP

class Solution:
    def longestSquareStreak(self, nums: List[int]) -> int:
        self.numToLongestLength = dict({ num: -1 for num in nums })

        longestLength = -1
        for num in nums:
            localLongestLength = self.getLongestLength(num)
            if localLongestLength > 1:
                longestLength = max(longestLength, self.getLongestLength(num))

        return longestLength

    def getLongestLength(self, num: int) -> int:
        if self.numToLongestLength[num] != -1:
            return self.numToLongestLength[num]

        self.numToLongestLength[num] = 1 + self.getLongestLength(num ** 2) if (num ** 2) in self.numToLongestLength else 1
        return self.numToLongestLength[num]

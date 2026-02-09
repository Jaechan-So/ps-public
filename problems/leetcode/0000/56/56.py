# 56. Merge Intervals
# https://leetcode.com/problems/merge-intervals/

from typing import *

class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        result = []

        for end, start in sorted([[e, s] for s, e in intervals]):
            while result and start <= result[-1][1]:
                start = min(start, result[-1][0])
                end = max(end, result[-1][1])
                result.pop()

            result.append([start, end])

        return result

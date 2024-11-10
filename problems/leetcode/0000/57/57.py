# 57. Insert Interval
# https://leetcode.com/problems/insert-interval/description/

# 1. Naive Solution
# 현재 interval보다 앞에 있고 겹치지 않는 경우 - 그냥 삽입
# 현재 interval보다 앞에 있고 겹치는 경우 - max(end)로 갱신하고 다음으로 넘어감

from typing import *

class Solution:
    def insert(self, intervals: List[List[int]], newInterval: List[int]) -> List[List[int]]:
        n = len(intervals)
        result = []
        newStart, newEnd = newInterval
        newIntervalInserted = False

        for i in range(n):
            start, end = intervals[i]

            if not newIntervalInserted and newStart <= start:
                result.append(list(newInterval))
                newIntervalInserted = True

            if result and start <= result[-1][1]:
                result[-1][1] = max(result[-1][1], end)
            else:
                result.append([start, end])

            if not newIntervalInserted and result and newStart <= result[-1][1]:
                result[-1][1] = max(result[-1][1], newEnd)
                newIntervalInserted = True

        if not newIntervalInserted:
            result.append(list(newInterval))

        return result

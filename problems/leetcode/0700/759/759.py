# 759. Employee Free Time
# https://leetcode.com/problems/employee-free-time/description/

from collections import heapq
from typing import *

# 각 Employee별로 가장 일찍 시작하는 Interval을 계속 확인한다
# 마지막 Interval의 end보다 그 다음 Interval이 더 늦게 시작하면, common free time으로 간주 가능
# Priority Queue에 (시작 시간, employeeIndex, intervalIndex)를 저장
# 시작은 end = 0으로 간주 가능

# Definition for an Interval.
class Interval:
    def __init__(self, start: int = None, end: int = None):
        self.start = start
        self.end = end

class Solution:
    def employeeFreeTime(self, schedule: 'List[List[Interval]]') -> 'List[Interval]':
        pq = [(employee[0].start, i, 0) for i, employee in enumerate(schedule)] # heapq
        heapq.heapify(pq)

        freeTimes = []
        currentEnd = pq[0][0]
        while len(pq) > 0:
            _, employeeIndex, intervalIndex = heapq.heappop(pq)
            interval = schedule[employeeIndex][intervalIndex]
            if currentEnd < interval.start:
                freeTimes.append(Interval(currentEnd, interval.start))

            currentEnd = max(currentEnd, interval.end)
            if intervalIndex < len(schedule[employeeIndex]) - 1:
                heapq.heappush(pq, (schedule[employeeIndex][intervalIndex + 1].start, employeeIndex, intervalIndex + 1))

        return freeTimes

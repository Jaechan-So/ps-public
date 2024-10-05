# 1235. Maximum Profit in Job Scheduling
# https://leetcode.com/problems/maximum-profit-in-job-scheduling/description/

from typing import *

# endTime의 오름차순으로 정렬
# 작은 순서대로 확인하면, 우선 매번 차례가 온 Job의 startTime 이전에 완료된 모든 Job들을 거쳐온 상태임
# Binary Search를 이용해서 이전의 최대값을 구하고, 반드시 누적 profit들이 오름차순이 되게 만들기.
# 동일한 endTime에 대한 profit이 이미 있고 더 높은 profit을 알게 되면 무조건 바꿔야 함.

class Solution:
    def jobScheduling(self, startTime: List[int], endTime: List[int], profit: List[int]) -> int:
        jobs = list(sorted([(endTime[i], startTime[i], profit[i]) for i in range(len(startTime))]))
        cumulativeProfits = [] # [endTime, profit]

        def findLargestProfit(et: int) -> int:
            start, end = 0, len(cumulativeProfits)
            target = et + 1

            while start < end:
                mid = (start + end) // 2
                if cumulativeProfits[mid][0] < target:
                    start = mid + 1
                else:
                    end = mid

            return cumulativeProfits[start - 1][1] if start > 0 else 0

        for e, s, p in jobs:
            maxProfit = p + findLargestProfit(s)

            if len(cumulativeProfits) > 0 and maxProfit <= cumulativeProfits[-1][1]:
                continue

            if len(cumulativeProfits) == 0 or cumulativeProfits[-1][0] < e:
                cumulativeProfits.append([e, maxProfit])
            else:
                cumulativeProfits[-1][1] = maxProfit

        return cumulativeProfits[-1][1]

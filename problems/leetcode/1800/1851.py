# 1851. Minimum Interval to Include Each Query
# https://leetcode.com/problems/minimum-interval-to-include-each-query/description

# Goal: O(logn)의 시간 복잡도로 l <= q <= r을 만족하는 최소 크기의 인터벌을 찾자.
# 미리 interval을 정렬해둔다고 하자.
# l <= q를 만족하는 interval들은 그럼 Binary Search로 O(logn)에 찾아진다.
# q <= r을 만족하는 interval들을 거기서 구해야 한다.

# Solution
# intervals와 queries를 같이 정렬한다.

import heapq
from typing import *

class Solution:
    def minInterval(self, intervals: List[List[int]], queries: List[int]) -> List[int]:
        n, q = len(intervals), len(queries)

        queriesWithIndex = [(query, i) for i, query in enumerate(queries)]
        queriesWithIndex.sort()
        intervals.sort()

        # heapq
        # (interval length, start, end)
        pq = []

        result = [-1 for _ in range(q)]
        j = 0
        for query, i in queriesWithIndex:
            while j < n and intervals[j][0] <= query:
                heapq.heappush(pq, (intervals[j][1] - intervals[j][0] + 1, intervals[j][0], intervals[j][1]))
                j += 1

            while pq and query > pq[0][2]:
                heapq.heappop(pq)

            result[i] = pq[0][0] if pq else -1

        return result

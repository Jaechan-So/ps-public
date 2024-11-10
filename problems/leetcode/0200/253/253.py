# 253. Meeting Rooms II
# https://leetcode.com/problems/meeting-rooms-ii/description/

# 1. Priority Queue
# 현재 사용중인 회의실의 다음 사용 가능 시간을 Min Heap에 저장, 최대한 이미 있는 회의실을 사용
# 모두 끝났을 때 Priority Queue의 크기를 반환하면 됨
# 이를 위해서 미리 intervals를 시작 시간에 대해서 오름차순 정렬해둬야 함

import heapq
from typing import *

class Solution:
    def minMeetingRooms(self, intervals: List[List[int]]) -> int:
        # heapq
        # (end time)
        occupied = []

        for start, end in sorted(intervals):
            if occupied and occupied[0] <= start:
                heapq.heappop(occupied)
            heapq.heappush(occupied, end)

        return len(occupied)

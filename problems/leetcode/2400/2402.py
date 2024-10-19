# 2402. Meeting Rooms III
# https://leetcode.com/problems/meeting-rooms-iii/description

import heapq
from typing import *

# 1. 현재 사용 가능한 방을 알 수 있어야 함.
# 2. Priority Queue로 방을 관리하는 경우, 이미 이전 미팅이 끝나서 사용 가능한 방 중 방 번호로 방을 골라야 하므로, 확실하지 않을 수 있음
# 3. Priority Queue를 2개 사용 - 사용 중인 방과 사용 중이지 않은 방
# 4. meetings를 오름차순으로 정렬해둔 뒤, 각 meeting마다 사용 중인 방에서 끝난 것들을 빼서 사용 중이지 않은 방으로 넣고, 사용 중이지 않은 방에서 하나를 빼서 사용
# 5. 사용 중이지 않은 방이 없는 경우, 각 meeting을 수정해서 진행할 수 있음. 어차피 이후의 미팅들도 동일한 delay를 가질 것임.

class Solution:
    def mostBooked(self, n: int, meetings: List[List[int]]) -> int:
        # heapq
        # using: Min Heap, (End Time, Room Number)
        # idle: Min Heap, (Room Number)
        using, idle = [], [i for i in range(n)]
        meetingCounts = [0 for _ in range(n)]

        delayedStart = -1
        for start, end in sorted(meetings):
            if len(idle) == 0 and start < using[0][0]:
                delayedStart = using[0][0]

            if delayedStart > 0 and start < delayedStart:
                diff = delayedStart - start
                start += diff
                end += diff

            while len(using) > 0 and using[0][0] <= start:
                _, roomNum = heapq.heappop(using)
                heapq.heappush(idle, roomNum)

            roomNum = heapq.heappop(idle)
            meetingCounts[roomNum] += 1
            heapq.heappush(using, (end, roomNum))

        return meetingCounts.index(max(meetingCounts))

# 1944. Number of Visible People in a Queue
# https://leetcode.com/problems/number-of-visible-people-in-a-queue/

from collections import deque
from typing import *

# Monotonic Queue
# 오른쪽부터 Queue에 쌓는다. (Monotonically Decreasing)
# 이렇게 쌓으면 자기보다 큰 게 나왔을 때 강제로 멈추게 되고, 그 사이에 뺐던 원소들은 조건을 만족하는 쌍임.

class Solution:
    def canSeePersonsCount(self, heights: List[int]) -> List[int]:
        q = deque()
        counts = [0] * len(heights)

        for i, height in enumerate(reversed(heights)):
            while q and height > q[-1]:
                q.pop()
                counts[len(heights) - i - 1] += 1

            if q:
                counts[len(heights) - i - 1] += 1

            q.append(height)

        return counts

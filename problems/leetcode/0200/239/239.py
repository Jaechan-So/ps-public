# 239. Sliding Window Maximum
# https://leetcode.com/problems/sliding-window-maximum/description/

from collections import deque
from typing import *

# 1. 자료구조 내의 최댓값을 구할 수 있어야 함
# 2. 특정 구간을 지냈을 때 해당 원소를 빼낼 수 있어야 함
# Priority Queue + Lazy Update
# Monotonic Decreasing Deque

class Solution:
    def __init__(self):
        self.dq = deque()

    def insert(self, num: int, index: int) -> None:
        while len(self.dq) > 0 and self.dq[-1][0] <= num:
            self.dq.pop()
        self.dq.append((num, index))

    def expire(self, index: int) -> None:
        while len(self.dq) > 0 and self.dq[0][1] < index:
            self.dq.popleft()

    def maxSlidingWindow(self, nums: List[int], k: int) -> List[int]:
        for i, num in enumerate(nums[:k]):
            self.insert(num, i)

        maxValues = []
        maxValues.append(self.dq[0][0])

        for i, num in enumerate(nums[k:]):
            index = i + k
            self.expire(i + 1)
            self.insert(num, index)
            maxValues.append(self.dq[0][0])

        return maxValues

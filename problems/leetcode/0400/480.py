# 480. Sliding Window Median
# https://leetcode.com/problems/sliding-window-median/description/

import heapq
from typing import *

# Max and Min Heap + Lazy Deletion
# 작은 수들을 Max Heap에, 큰 수들을 Min Heap에 저장
# Index를 Tuple로 같이 저장하고, 더 이상 필요없는 Index는 Lazy Deletion

# 1. 빠지는 Index에 대해서 Delete
# 2. 추가되는 Index에 대해서 저장
# 3. 만약 빠지는 값이 Max Heap 안에 있다면, Min Heap에서 Max Heap으로 하나 옮겨야 함. 이를 통해 Balancing이 가능.

class Solution:
    def medianSlidingWindow(self, nums: List[int], k: int) -> List[float]:
        n = len(nums)

        # smaller: Max Heap (-value, index)
        # larger: Min Heap (value, index)
        smaller, larger = [], []
        def getMedian() -> float:
            even = k % 2 == 0
            return float((-smaller[0][0] + larger[0][0]) / 2) if even else float(larger[0][0])

        for i, num in enumerate(nums[:k]):
            heapq.heappush(larger, (num, i))
        for _ in range(k // 2):
            num, i = heapq.heappop(larger)
            heapq.heappush(smaller, (-num, i))

        medians = [getMedian()]

        for i in range(k, n):
            if nums[i] >= larger[0][0]:
                heapq.heappush(larger, (nums[i], i))
                if nums[i - k] <= larger[0][0]:
                    num, j = heapq.heappop(larger)
                    heapq.heappush(smaller, (-num, j))
            else:
                heapq.heappush(smaller, (-nums[i], i))
                if nums[i - k] >= -smaller[0][0]:
                    num, j = heapq.heappop(smaller)
                    heapq.heappush(larger, (-num, j))

            while len(smaller) > 0 and smaller[0][1] <= i - k:
                heapq.heappop(smaller)
            while len(larger) > 0 and larger[0][1] <= i - k:
                heapq.heappop(larger)

            medians.append(getMedian())

        return medians

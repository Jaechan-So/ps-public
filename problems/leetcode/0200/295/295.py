# 295. Find Median from Data Stream
# https://leetcode.com/problems/find-median-from-data-stream/description/

from collections import heapq

class MedianFinder:

    def __init__(self):
        # heapq
        # len(self.smaller) >= len(self.larger)
        # self.smaller -> Max Heap (Negative)
        self.smaller, self.larger = [], []

    def addNum(self, num: int) -> None:
        if len(self.smaller) == 0:
            heapq.heappush(self.smaller, -num)
            return

        if num <= -self.smaller[0]:
            heapq.heappush(self.smaller, -num)
        else:
            heapq.heappush(self.larger, num)

        if len(self.smaller) > len(self.larger) + 1:
            numToLarger = -heapq.heappop(self.smaller)
            heapq.heappush(self.larger, numToLarger)
        elif len(self.smaller) < len(self.larger):
            numToSmaller = heapq.heappop(self.larger)
            heapq.heappush(self.smaller, -numToSmaller)

    def findMedian(self) -> float:
        evenTotalLength = (len(self.smaller) + len(self.larger)) % 2 == 0

        if evenTotalLength:
            return float((-self.smaller[0] + self.larger[0]) / 2)
        return float(-self.smaller[0])


# Your MedianFinder object will be instantiated and called as such:
# obj = MedianFinder()
# obj.addNum(num)
# param_2 = obj.findMedian()

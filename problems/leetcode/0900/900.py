# 900. RLE Iterator
# https://leetcode.com/problems/rle-iterator

import bisect
from typing import *

# 1. 현재 Encoding 그룹에서 남은 개수를 추적하면 됨

# 2. Binary Search로도 접근 가능

class RLEIterator:

    def __init__(self, encoding: List[int]):
        self.index = 0
        self.counts = [0]
        self.nums = [float("-inf")]

        for i in range(len(encoding) // 2):
            count, num = encoding[2 * i], encoding[2 * i + 1]

            if count > 0:
                self.counts.append(self.counts[-1] + count)
                self.nums.append(num)

    def next(self, n: int) -> int:
        self.index += n
        countIndex = bisect.bisect_left(self.counts, self.index)
        return -1 if countIndex == len(self.counts) else self.nums[countIndex]


# Your RLEIterator object will be instantiated and called as such:
# obj = RLEIterator(encoding)
# param_1 = obj.next(n)

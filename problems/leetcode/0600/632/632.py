# 632. Smallest Range Covering Elements from K Lists
# https://leetcode.com/problems/smallest-range-covering-elements-from-k-lists/description/

from collections import heapq
from typing import *

class Solution:
    def smallestRange(self, nums: List[List[int]]) -> List[int]:
        maxNum = max([l[0] for l in nums])
        smallestPq = [(l[0], i, 0) for i, l in enumerate(nums)] # heapq
        heapq.heapify(smallestPq)
        rng = [smallestPq[0][0], maxNum]

        total = sum([len(l) for l in nums])
        minFixedNum = float("inf")
        for i in range(total):
            num, listIndex, elementIndex = heapq.heappop(smallestPq)

            if elementIndex < len(nums[listIndex]) - 1:
                heapq.heappush(smallestPq, (nums[listIndex][elementIndex + 1], listIndex, elementIndex + 1))
                maxNum = max(maxNum, nums[listIndex][elementIndex + 1])
            else:
                minFixedNum = min(minFixedNum, num)

            minNum = minFixedNum
            if len(smallestPq) > 0:
                minNum = min(minNum, smallestPq[0][0])
            if maxNum - minNum < rng[1] - rng[0]:
                rng = [minNum, maxNum]

        return rng

# 2799. Count Complete Subarrays in an Array
# https://leetcode.com/problems/count-complete-subarrays-in-an-array/description

# 일단 전체 nums는 반드시 조건을 만족하므로, 여기서부터 시작
# nums의 양 끝을 계속 줄여나가면서 Backtracking
# 개수는 HashMap을 들고 있으면서 추적할 수 있음

from collections import defaultdict
from typing import *

class Solution:
    def countCompleteSubarrays(self, nums: List[int]) -> int:
        n = len(nums)
        self.elementCount = defaultdict(int)
        self.visited = set()

        for num in nums:
            self.elementCount[num] += 1

        return self.getSubarrayTotalCount(nums, 0, n - 1)

    def getSubarrayTotalCount(self, nums: List[int], start: int, end: int) -> int:
        self.visited.add((start, end))
        totalCount = 1

        if start == end:
            return totalCount

        leftElement = nums[start]
        self.elementCount[leftElement] -= 1
        if self.elementCount[leftElement] > 0 and (start + 1, end) not in self.visited:
            totalCount += self.getSubarrayTotalCount(nums, start + 1, end)
        self.elementCount[leftElement] += 1

        rightElement = nums[end]
        self.elementCount[rightElement] -= 1
        if self.elementCount[rightElement] > 0 and (start, end - 1) not in self.visited:
            totalCount += self.getSubarrayTotalCount(nums, start, end - 1)
        self.elementCount[rightElement] += 1

        print(start, end, totalCount)
        return totalCount

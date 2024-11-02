# 2035. Partition Array Into Two Arrays to Minimize Sum Difference
# https://leetcode.com/problems/partition-array-into-two-arrays-to-minimize-sum-difference/description

# 1. Naive Solution - DFS (Backtracking)

# 2. Meet in the middle - 2^2n은 불가능, 2^n은 가능하므로

import bisect
from collections import defaultdict
from itertools import combinations
from typing import *

class Solution:
    def minimumDifference(self, nums: List[int]) -> int:
        n = len(nums) // 2
        leftCountToSums, rightCountToSums = self.getCountToSums(nums[:n]), self.getCountToSums(nums[n:])

        totalSum = sum(nums)
        halfSum = totalSum // 2
        minDiff = float("inf")
        for leftCount in range(0, n + 1):
            rightCount = n - leftCount
            rightSums = rightCountToSums[rightCount]
            rightSums.sort()

            for s in leftCountToSums[leftCount]:
                candidate = bisect.bisect_left(rightSums, halfSum - s)
                for c in [candidate, candidate - 1]:
                    if 0 <= c < len(rightSums):
                        minDiff = min(minDiff, abs(totalSum - 2 * (s + rightSums[c])))

        return minDiff

    def getCountToSums(self, nums: List[int]) -> dict[int, List[int]]:
        n = len(nums)
        countToSums = defaultdict(list[int])

        countToSums[0] = [0]
        for i in range(1, n + 1):
            countToSums[i] = [sum(c) for c in combinations(nums, i)]

        return countToSums

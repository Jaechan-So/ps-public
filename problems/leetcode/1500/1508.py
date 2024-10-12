# 1508. Range Sum of Sorted Subarray Sums
# https://leetcode.com/problems/range-sum-of-sorted-subarray-sums/description

from typing import *

# 1. 모든 sum을 구하고 정렬 (O(n^2logn))
# 2. 실제로 합을 구함
# 3. Priority Queue를 이용해서 약간의 최적화는 가능하나, 근본적으로 시간 복잡도를 줄이지는 않음

class Solution:
    def rangeSum(self, nums: List[int], n: int, left: int, right: int) -> int:
        sums = []

        for i in range(n):
            currentSum = 0
            for j in range(i, n):
                currentSum += nums[j]
                sums.append(currentSum)

        sums.sort()

        totalSum = 0
        for i in range(left - 1, right):
            totalSum += sums[i]
            totalSum %= int(1e9 + 7)

        return totalSum

# 410. Split Array Largest Sum
# https://leetcode.com/problems/split-array-largest-sum/description

# 1. Naive Solution
# 특정 subarray의 합을 구한 뒤, 남은 subarray에서 k - 1개만큼의 subarray를 고려하는 것을 이용해서 DP 사용 가능

# 2. Parametric Search
# 구간 내에서 특정 합 이하로 subarray들을 만들었을 때 개수가 k개 미만인지를 반복해서 체크

from typing import *

class Solution:
    def splitArray(self, nums: List[int], k: int) -> int:
        left, right = max(nums), sum(nums)

        while left < right:
            maxSum = (left + right) // 2

            if self.getSubarrayCountWithMaxSum(nums, maxSum) <= k:
                right = maxSum
            else:
                left = maxSum + 1

        return left

    def getSubarrayCountWithMaxSum(self, nums: List[int], maxSum: int) -> int:
        currentSum = 0
        subarrays = 1

        for num in nums:
            if currentSum + num <= maxSum:
                currentSum += num
            else:
                currentSum = num
                subarrays += 1

        return subarrays

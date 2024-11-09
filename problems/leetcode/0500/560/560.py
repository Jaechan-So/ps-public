# 560. Subarray Sum Equals K
# https://leetcode.com/problems/subarray-sum-equals-k/description/

from collections import defaultdict
from typing import *

class Solution:
    def subarraySum(self, nums: List[int], k: int) -> int:
        prefixSums = defaultdict(int)
        prefixSums[0] += 1
        totalSum, totalCount = 0, 0

        for num in nums:
            totalSum += num
            totalCount += prefixSums[totalSum - k]
            prefixSums[totalSum] += 1

        return totalCount

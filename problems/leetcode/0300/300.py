# 300. Longest Increasing Subsequence
# https://leetcode.com/problems/longest-increasing-subsequence/description/

import bisect
from typing import *

class Solution:
    def lengthOfLIS(self, nums: List[int]) -> int:
        candidates = []

        for num in nums:
            if len(candidates) == 0 or num > candidates[-1]:
                candidates.append(num)
                continue

            index = bisect.bisect_left(candidates, num)
            candidates[index] = num

        return len(candidates)

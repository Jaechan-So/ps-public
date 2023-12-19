# 1590. Make Sum Divisible by P
# https://leetcode.com/problems/make-sum-divisible-by-p/description/


from typing import *


class Solution:
    def minSubarray(self, nums: List[int], p: int) -> int:
        total = sum(nums)
        if (total % p) == 0:
            return 0

        length, s = 1e6, 0

        remainders = dict()
        remainders[0] = -1

        for i in range(len(nums)):
            s += nums[i]
            target = (p + (s % p) - (total % p)) % p
            if target in remainders:
                length = min(length, i - remainders[target])
            remainders[s % p] = i

        return length if length < len(nums) else -1

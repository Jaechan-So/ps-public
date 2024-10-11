# 525. Contiguous Array
# https://leetcode.com/problems/contiguous-array/description/

from typing import *

class Solution:
    def findMaxLength(self, nums: List[int]) -> int:
        contiguousLength = float("-inf")

        differences = dict()
        differences[0] = -1

        counts = [0, 0]
        for i, num in enumerate(nums):
            counts[num] += 1
            diff = counts[1] - counts[0]

            if diff in differences:
                contiguousLength = max(contiguousLength, i - differences[diff])
            else:
                differences[diff] = i

        return 0 if contiguousLength == float("-inf") else contiguousLength

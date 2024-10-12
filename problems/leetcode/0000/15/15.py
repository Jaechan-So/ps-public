# 15. 3Sum
# https://leetcode.com/problems/3sum/description/

from typing import *

class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        nums.sort()
        triplets = set()

        for i, pivot in enumerate(nums):
            if pivot > 0:
                break
            if i > 0 and nums[i - 1] == nums[i]:
                continue

            visited = set()
            for num in nums[i + 1:]:
                complement = -pivot - num

                if complement in visited:
                    triplets.add((pivot, complement, num))

                visited.add(num)

        return [list(triplet) for triplet in triplets]

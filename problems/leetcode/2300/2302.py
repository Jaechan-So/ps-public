# 2302. Count Subarrays With Score Less Than K
# https://leetcode.com/problems/count-subarrays-with-score-less-than-k/description

# 1. Naive Solution
# 모든 subarray에 대해서, Prefix Sum과 길이를 이용해서 직접 score를 구함 - O(n^2)

# 2. Binary Search??
# Score 배열을 동적으로 O(1)에 구할 수 있다면, 이 때 Binary Search를 이용해서 O(nlogn)이 가능할듯함.
# Score 배열을 O(1)에 구할 수 없어보임.

# 3. Sliding Window

from typing import *

class Solution:
    def countSubarrays(self, nums: List[int], k: int) -> int:
        n = len(nums)
        left, right, total, subarrays = 0, 0, 0, 0

        while right < n:
            total += nums[right]

            while total * (right - left + 1) >= k:
                total -= nums[left]
                left += 1

            subarrays += (right - left + 1)
            right += 1

        return subarrays

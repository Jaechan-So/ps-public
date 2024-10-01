# 1526. Minimum Number of Increments on Subarrays to Form a Target Array
# https://leetcode.com/problems/minimum-number-of-increments-on-subarrays-to-form-a-target-array/description

from typing import *

# Greedy Approach
# target array의 가장 위/아래부터 최대한 한 번에 많이 제거하면 됨
# 작아졌을 때 - 그 차이만큼 더해야 함
# 커졌을 때 - 더하지 않아도 됨

class Solution:
    def minNumberOperations(self, target: List[int]) -> int:
        n = len(target)

        operations = target[n - 1]
        for i in range(n - 1):
            operations += max(target[i] - target[i + 1], 0)

        return operations

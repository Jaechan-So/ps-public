# 1671. Minimum Number of Removals to Make Mountain Array
# https://leetcode.com/problems/minimum-number-of-removals-to-make-mountain-array/description

# 배열의 최댓값은 무조건 선택하는게 유리함.
# 최댓값 기준으로 왼쪽, 오른쪽을 나눠서 Monotonically Decreasing이 되도록 하는 최소 횟수를 구하면 됨.
# 최댓값이 1개가 아니고, 띄엄띄엄 띄어져 있다면?

# 각각의 Pivot Index에 대해서, 양 쪽을 기준으로
# Longest Increasing/Decreasing Subsequence를 구하면 된다. (단 Pivot 값보다는 작아야 함)
# T(nlogn), S(n)

import bisect
from typing import *

class Solution:
    def minimumMountainRemovals(self, nums: List[int]) -> int:
        n = len(nums)
        maxMountainArrayLengths = [0 for _ in range(n)]

        for init, start, end, step in [(nums[0], 1, n - 1, 1), (nums[n - 1], n - 2, 0, -1)]:
            mono = [init]
            for i in range(start, end, step):
                index = bisect.bisect_left(mono, nums[i])
                if index > 0 and maxMountainArrayLengths[i] >= 0:
                    maxMountainArrayLengths[i] += index
                elif index == 0:
                    maxMountainArrayLengths[i] = -1

                if index == len(mono):
                    mono.append(nums[i])
                else:
                    mono[index] = nums[i]

        return n - 1 - max(maxMountainArrayLengths)

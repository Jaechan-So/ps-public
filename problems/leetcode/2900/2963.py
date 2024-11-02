# 2963. Count the Number of Good Partitions
# https://leetcode.com/problems/count-the-number-of-good-partitions/description

# 각 수마다 처음 등장과 마지막 등장을 미리 기록한다.
# 최소한의 단위 배열들을 찾아낸다.
# 단위 배열의 개수를 n이라고 했을 때, 2^(n - 1)개가 정답이 된다. (1 << (n - 1))

from typing import *

class Solution:
    def numberOfGoodPartitions(self, nums: List[int]) -> int:
        n = len(nums)

        numToLastIndex = dict()
        for i, num in enumerate(nums):
            numToLastIndex[num] = i

        subarrays = 0
        i, right = 0, float("-inf")
        while i < n:
            right = max(right, numToLastIndex[nums[i]])
            if right == i:
                subarrays += 1
            i += 1

        return (1 << (subarrays - 1)) % int(1e9 + 7)

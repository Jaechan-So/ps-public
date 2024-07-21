# Median이 k이려면, k는 반드시 배열에 포함되어야 함.
# k 기준으로 왼쪽과 오른쪽 subarray를 나눈다고 가정하자.
# 왼쪽 subarray에서, Prefix Sum과 같이 k보다 작고 큰 개수를 하나의 숫자로 나타낼 수 있음.
# 오른쪽 subarray도 마찬가지.
# 이 개수를 map으로 저장해서, 더하기만 하면 될 것 같음.
# 다만, 홀수 짝수가 좀 달라서 한 번에 깔끔하게 되지는 않을 것 같음.
# map에 크고 작고 개수 + 홀,짝을 key로 value를 개수로 해야 할듯.

from collections import defaultdict
from typing import *

class Solution:
    def countSubarrays(self, nums: List[int], k: int) -> int:
        n, kIndex = len(nums), nums.index(k)

        differences, currentDiff = defaultdict(int), 0
        differences[(0, True)] += 1
        for i in range(kIndex + 1, n):
            currentDiff += (1 if nums[i] > k else -1)
            isEvenCount = (i - kIndex) % 2 == 0
            differences[(currentDiff, isEvenCount)] += 1

        currentDiff = sum([(1 if x > k else -1) for x in nums[:kIndex]])
        totalSubarrays = 0
        for i in range(0, kIndex + 1):
            currentCount = kIndex - i
            isEvenCount = currentCount % 2 == 0

            # isEvenCount가 True이면, differences에서 짝수일 때는 합이 0, 홀수일 때는 합이 1이 되어야 함
            # isEvenCount가 False이면, differences에서 짝수일 때는 합이 1, 홀수일 때는 합이 0이 되어야 함
            totalSubarrays += differences[((0 if isEvenCount else 1) - currentDiff, True)]
            totalSubarrays += differences[((1 if isEvenCount else 0) - currentDiff, False)]

            currentDiff += (-1 if nums[i] > k else 1)

        return totalSubarrays

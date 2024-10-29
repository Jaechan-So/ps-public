# 2025. Maximum Number of Ways to Partition an Array
# https://leetcode.com/problems/maximum-number-of-ways-to-partition-an-array/description

from collections import defaultdict
from typing import *

# 특정한 수를 k로 바꿀 때, k - num 만큼의 변화가 발생한다.
# 왼쪽부터 pivot으로 가능한 경우의 수들을 쭉 순회하면서, pivot의 왼쪽과 오른쪽의 합 차이를 구해둔다.
# 안 바꿨을 때는 0의 개수가 곧 partition이 가능한 pivot의 개수이다.
# 인덱스 0이 각 pivot 케이스에서는 무조건 leftSum에만 영향을 미친다.
# 인덱스 1은 처음에만 rightSum, 그 이후에는 무조건 leftSum에만 영향을 미친다.
# ...

class Solution:
    def waysToPartition(self, nums: List[int], k: int) -> int:
        n, totalSum = len(nums), sum(nums)

        leftSum = 0
        diffs = defaultdict(int)
        for i in range(n - 1):
            leftSum += nums[i]
            rightSum = totalSum - leftSum
            diffs[rightSum - leftSum] += 1

        leftSum = 0
        partitions = max(diffs[0], diffs[k - nums[0]])
        for i in range(1, n):
            leftSum += nums[i - 1]
            rightSum = totalSum - leftSum

            diffs[leftSum - rightSum] += 1
            diffs[rightSum - leftSum] -= 1

            partitions = max(partitions, diffs[k - nums[i]])

        return partitions

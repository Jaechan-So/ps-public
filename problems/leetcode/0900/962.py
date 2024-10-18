# 962. Maximum Width Ramp
# https://leetcode.com/problems/maximum-width-ramp/description

from typing import *

# 특정 인덱스 j를 기준으로, 이전 인덱스에서 nums[j]보다 작거나 같은, 처음 만나는 수를 찾을 수 있어야 함
# Monotonic Increasing Stack을 이용해서, Binary Search
# O(nlogn)

# 먼저 크기 순대로 정렬
# 뒤에 나오는 수는 무조건 앞의 수보다 크거나 같음.
# Index의 최솟값을 계속 추적하면 될듯.
# O(nlogn)

# Two Pointer
# 특정 인덱스 i를 기준으로, 남은 배열의 최댓값을 미리 구하면 좋음
# 만약 특정 인덱스 i와 j에 대해서, nums[i] <= rightMax[j] 이면, 결국 j 혹은 그보다 오른쪽에 조건을 만족하는 인덱스가 존재함.
# 따라서 조건을 만족하는 동안 j를 계속 증가시키다가, 조건이 안 되는 순간 i를 증가시켜서 계속 진행.
# 어차피 i를 증가시켰는데 nums[i]가 작아졌더라도, 이미 나올 수 있는 최대 길이는 이전에 정해졌기 때문에 문제 없음

# Monotonic Stack
# Monotonically Decreasing Stack을 만들어두면, Ramp의 시작점일 가능성이 있는 후보들을 모두 알 수 있다.
# 왜냐하면, Increasing의 경우에는 왼쪽 원소가 무조건 상위호환이기 때문이다. (더 작고 더 왼쪽에 있기 때문에)
# 그렇기 때문에 Stack을 만들고, nums 배열을 오른쪽에서부터 순회하면서 Stack에서 왼쪽 시작점의 후보들을 빼내면서 가면 된다.

class Solution:
    def maxWidthRamp(self, nums: List[int]) -> int:
        n = len(nums)
        mono = []

        for i, num in enumerate(nums):
            if len(mono) == 0 or nums[mono[-1]] > num:
                mono.append(i)

        maxWidth = 0
        for i in range(n - 1, -1, -1):
            while len(mono) > 0 and nums[mono[-1]] <= nums[i]:
                maxWidth = max(maxWidth, i - mono[-1])
                mono.pop()

        return maxWidth

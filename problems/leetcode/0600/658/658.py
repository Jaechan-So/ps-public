# 658. Find K Closest Elements
# https://leetcode.com/problems/find-k-closest-elements/description/

# 1. Naive Solution
# 주어진 정렬된 배열에서 x의 lower bound와 그 바로 전 원소 중 하나가 가장 가까운 원소
# 그 원소를 기준으로 Two Pointer를 이용해서 k개를 선정
# T(logn + k)

# 2. Solution
# Lower Bound를 직접 Binary Search로 찾기

from typing import *

class Solution:
    def findClosestElements(self, arr: List[int], k: int, x: int) -> List[int]:
        n = len(arr)
        left, right = 0, n - k

        while left < right:
            mid = (left + right) // 2

            if x - arr[mid] > arr[mid + k] - x:
                left = mid + 1
            else:
                right = mid

        return arr[left:left + k]

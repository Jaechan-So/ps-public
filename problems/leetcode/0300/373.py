# 373. Find K Pairs with Smallest Sums
# https://leetcode.com/problems/find-k-pairs-with-smallest-sums/description

from collections import heapq
from typing import *

# Priority Queue에 (합, index1, index2) 들을 저장한다.
# 이 때, Tuple에서 index2만 움직이고 index1은 고정할 수 있도록 초기에 index1을 모두 커버하도록 넣는다.
# Priority Queue에서 1개가 빠지면, index2를 움직여서 넣는다.

class Solution:
    def kSmallestPairs(self, nums1: List[int], nums2: List[int], k: int) -> List[List[int]]:
        pq = [(num1 + nums2[0], i, 0) for i, num1 in enumerate(nums1)] # heapq
        heapq.heapify(pq)

        pairs = []
        while k > 0:
            twoSum, index1, index2 = heapq.heappop(pq)
            pairs.append([nums1[index1], nums2[index2]])

            if index2 + 1 < len(nums2):
                heapq.heappush(pq, (nums1[index1] + nums2[index2 + 1], index1, index2 + 1))

            k -= 1

        return pairs

# 2898. Maximum Linear Stock Score
# https://leetcode.com/problems/maximum-linear-stock-score/description

# 가장 첫 번째 원소로부터의 거리를 Linear Group의 식별자로 사용할 수 있음
# 필요한 자료구조
# 1. Group to Sum - dict

from typing import *

class Solution:
    def maxScore(self, prices: List[int]) -> int:
        groupToSum = dict()

        for i, price in enumerate(prices):
            groupId = price - i
            groupToSum[groupId] = groupToSum.get(groupId, 0) + price

        return max(groupToSum.values())

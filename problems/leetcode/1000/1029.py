# 1029. Two City Scheduling
# https://leetcode.com/problems/two-city-scheduling/description

# 기본적으로 더 싼 도시를 선택한다.
# 한 쪽이 넘치는 경우, 손해가 더 적은 사람들이 반대 도시를 선택하도록 한다.
# 필요한 자료 구조
# 1. 전체 비용
# 2. A도시를 선택한 사람들의 차액, B도시를 선택한 사람들의 차액

from typing import *

class Solution:
    def twoCitySchedCost(self, costs: List[List[int]]) -> int:
        n = len(costs) // 2
        totalCost = 0
        aCostDiff, bCostDiff = [], []

        for aCost, bCost in costs:
            totalCost += min(aCost, bCost)
            if aCost < bCost:
                aCostDiff.append(bCost - aCost)
            else:
                bCostDiff.append(aCost - bCost)

        balancingDiff = aCostDiff if len(aCostDiff) >= len(bCostDiff) else bCostDiff
        d = len(balancingDiff)
        totalCost += sum(sorted(balancingDiff)[:d - n])

        return totalCost

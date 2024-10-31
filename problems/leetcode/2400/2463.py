# 2463. Minimum Total Distance Traveled
# https://leetcode.com/problems/minimum-total-distance-traveled/description

from typing import *

class Solution:
    def minimumTotalDistance(self, robot: List[int], factory: List[List[int]]) -> int:
        robot.sort()
        factory.sort()

        factories = []
        for pos, limit in factory:
            for _ in range(limit):
                factories.append(pos)

        robotCount, factoryCount = len(robot), len(factories)
        memo = [0 for _ in range(factoryCount + 1)]

        for i in range(robotCount - 1, -1, -1):
            if i != robotCount - 1:
                memo[factoryCount] = float("inf")

            newMemo = [0 for _ in range(factoryCount + 1)]
            newMemo[factoryCount] = float("inf")

            for j in range(factoryCount - 1, -1, -1):
                newMemo[j] = min(abs(robot[i] - factories[j]) + memo[j + 1], newMemo[j + 1])

            memo = newMemo

        return memo[0]

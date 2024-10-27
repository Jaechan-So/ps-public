# 134. Gas Station
# https://leetcode.com/problems/gas-station/description/

from typing import *

# gas[i] - cost[i]가 i번째에서 i + 1번째로 이동할 때의 통합 이득 또는 손실
# 현재까지의 차이 총합에서 Prefix Sum으로 계산한 차이의 총합을 뺐을 때, 음수가 나오면 출발 지점으로 불가능

# gas - cost의 역방향으로 계산해서 최댓값인 곳에서 시작하면 가장 유리함

class Solution:
    def canCompleteCircuit(self, gas: List[int], cost: List[int]) -> int:
        if sum(gas) - sum(cost) < 0:
            return -1

        n = len(gas)

        maxNet, currentNet, index = gas[n - 1] - cost[n - 1], gas[n - 1] - cost[n - 1], n - 1
        for i in range(n - 2, -1, -1):
            currentNet += (gas[i] - cost[i])
            if currentNet > maxNet:
                maxNet = currentNet
                index = i

        return index

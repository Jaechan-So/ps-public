# 787. Cheapest Flights Within K Stops
# https://leetcode.com/problems/cheapest-flights-within-k-stops/description/

from collections import defaultdict, deque
from typing import *

# BFS 방식 탐색

class Solution:
    def findCheapestPrice(self, n: int, flights: List[List[int]], src: int, dst: int, k: int) -> int:
        flightMap = defaultdict(defaultdict[int])
        for f, t, p in flights:
            flightMap[f][t] = p

        cheapest = dict()
        for i in range(n):
            cheapest[i] = 0 if i == src else float("inf")

        q = deque() # (nodeNum, currentPrice, currentStop)
        q.append((src, 0, 0))

        minPrice = float("inf")
        while len(q) > 0:
            nodeNum, currentPrice, currentStop = q.popleft()

            if nodeNum == dst:
                minPrice = min(minPrice, currentPrice)
                continue

            for nextNode, price in flightMap[nodeNum].items():
                if nextNode == dst or (currentStop < k and currentPrice + price < cheapest[nextNode]):
                    cheapest[nextNode] = currentPrice + price
                    q.append((nextNode, currentPrice + price, currentStop + 1))

        return -1 if minPrice == float("inf") else minPrice

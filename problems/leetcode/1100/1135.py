# 1135. Connecting Cities With Minimum Cost
# https://leetcode.com/problems/connecting-cities-with-minimum-cost/description/

# 1. Kruskal's Algorithm
# 비용이 낮은 순서대로 Edge(connections)를 정렬
# 각 Edge를 순회하면서 사용할 edge 리스트에 추가
# 사이클이 발생하면 안 되므로 Union Find 사용이 필수

from typing import *


class Solution:
    def minimumCost(self, n: int, connections: List[List[int]]) -> int:
        parents = [i for i in range(n + 1)]

        def findParent(n: int) -> int:
            if n != parents[n]:
                parents[n] = findParent(parents[n])

            return parents[n]

        def merge(n1: int, n2: int):
            p1, p2 = findParent(n1), findParent(n2)
            parents[p2] = p1

        edges = [[cost, x, y] for [x, y, cost] in connections]

        totalCost, totalEdges = 0, 0
        for cost, x, y in sorted(edges):
            if totalEdges == n - 1:
                break

            if findParent(x) != findParent(y):
                totalEdges += 1
                totalCost += cost
                merge(x, y)

        return totalCost if totalEdges == n - 1 else -1

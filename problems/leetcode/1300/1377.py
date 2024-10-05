# 1377. Frog Position After T Seconds
# https://leetcode.com/problems/frog-position-after-t-seconds/description

from collections import defaultdict
from typing import *

# DFS로 순회하면서 target에 도착했을 때 시간이 t랑 같으면 확률 반환, 아니면 0 반환.
# 추가적으로, 아직 횟수가 남았지만 더 이상 갈 노드가 없으면서 이미 대상 노드에 도착하는 경우도 확률 반환.

class Solution:
    def frogPosition(self, n: int, edges: List[List[int]], t: int, target: int) -> float:
        self.edgeMap = defaultdict(set[int])
        for v1, v2 in edges:
            self.edgeMap[v1].add(v2)
            self.edgeMap[v2].add(v1)

        self.visited = set()
        self.visited.add(1)

        return self.traverseTree(n, t, target, 1)

    def traverseTree(self, n: int, t: int, target: int, currentNode: int) -> float:
        prob = 0

        if t == 0:
            return 1 if currentNode == target else 0

        candidates = sum([int(v not in self.visited) for v in self.edgeMap[currentNode]])
        if candidates == 0 and t >= 0 and currentNode == target:
            return 1

        for vertex in self.edgeMap[currentNode]:
            if vertex not in self.visited:
                self.visited.add(vertex)
                prob = max(prob, float(1 / candidates) * self.traverseTree(n, t - 1, target, vertex))

        return prob

# 547. Number of Provinces
# https://leetcode.com/problems/number-of-provinces/description

from typing import *

class UnionFind:
    def __init__(self, n: int) -> None:
        self.parent = [i for i in range(n)]
        self.rank = [1 for _ in range(n)]

    def find(self, i: int) -> int:
        if self.parent[i] != i:
            self.parent[i] = self.find(self.parent[i])
        return self.parent[i]

    def merge(self, i: int, j: int) -> None:
        pi, pj = self.find(i), self.find(j)
        if self.rank[pi] < self.rank[pj]:
            pi, pj = pj, pi

        if self.rank[pi] == self.rank[pj]:
            self.rank[pi] += 1
        self.parent[pj] = pi

class Solution:
    def findCircleNum(self, isConnected: List[List[int]]) -> int:
        n = len(isConnected)
        uf = UnionFind(n)

        for i in range(n):
            for j in range(i + 1, n):
                if isConnected[i][j]:
                    uf.merge(i, j)

        return len(set([uf.find(i) for i in range(n)]))

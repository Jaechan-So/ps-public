# 952. Largest Component Size by Common Factor
# https://leetcode.com/problems/largest-component-size-by-common-factor/description

# 1. Naive Solution
# 모든 원소의 조합 간 조사 + Union Find -> Counter -> max(values)
# 조사하는데 T(n^2)이 걸리므로 TLE가 발생

# 2. 소인수 분해
# 특정 수를 소인수분해해서 들어가는 그룹끼리 모두 Union Find
# sqrt(n) 까지만 조사하면 됨.

from collections import defaultdict
from typing import *

class UnionFind:
    def __init__(self, n: int):
        self.parent = [i for i in range(n)]
        self.rank = [1 for i in range(n)]

    def find(self, i: int) -> int:
        if self.parent[i] != i:
            self.parent[i] = self.find(self.parent[i])
        return self.parent[i]

    def merge(self, i: int, j: int) -> None:
        if i == j:
            return

        pi, pj = self.find(i), self.find(j)
        if self.rank[pi] > self.rank[pj]:
            pi, pj = pj, pi

        self.parent[pi] = pj
        if self.rank[pi] == self.rank[pj]:
            self.rank[pj] += 1

class Solution:
    def largestComponentSize(self, nums: List[int]) -> int:
        uf = UnionFind(max(nums) + 1)
        numToRepresentativeFactor = dict()

        for num in nums:
            factors = list(self.getPrimeFactors(num))
            numToRepresentativeFactor[num] = factors[0]

            for i in range(1, len(factors)):
                uf.merge(factors[i - 1], factors[i])

        factorToCount = defaultdict(int)
        for num in nums:
            factor = uf.find(numToRepresentativeFactor[num])
            factorToCount[factor] += 1

        return max(factorToCount.values())

    def getPrimeFactors(self, n: int) -> set[int]:
        primeFactors = set()
        factor = 2

        while factor ** 2 <= n:
            if n % factor == 0:
                primeFactors.add(factor)
                n //= factor
            else:
                factor += 1

        primeFactors.add(n)

        return primeFactors

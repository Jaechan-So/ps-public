# 721. Accounts Merge
# https://leetcode.com/problems/accounts-merge/description/

# 1. 먼저 Union Find를 이용해서 같은 사람임을 검증해두어야 한다.
# 2. 같은 사람끼리 set에 이메일 주소를 저장해둔다.

from typing import *

class UnionFind:
    def __init__(self, n: int):
        self.n = n
        self.parent = list(range(n))
        self.rank = [1] * n

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
    def accountsMerge(self, accounts: List[List[str]]) -> List[List[str]]:
        n = len(accounts)
        uf = UnionFind(n)

        addressToIndex = dict() # (str, int)
        for i in range(n):
            samePersonIndicies = set()

            for address in accounts[i][1:]:
                if address in addressToIndex:
                    samePersonIndicies.add(addressToIndex[address])
                else:
                    addressToIndex[address] = i

            for j in samePersonIndicies:
                uf.merge(i, j)

        idxToAddresses = dict() # (int, set(str))
        for i in range(n):
            parent = uf.find(i)

            for address in accounts[i][1:]:
                if parent not in idxToAddresses:
                    idxToAddresses[parent] = set()
                idxToAddresses[parent].add(address)

        return [[accounts[index][0], *sorted(list(addresses))] for index, addresses in idxToAddresses.items()]

# 786. K-th Smallest Prime Fraction
# https://leetcode.com/problems/k-th-smallest-prime-fraction/description/

# 제일 작은 건 무조건 양 끝 원소를 골랐을 때.
# 이 케이스를 시작으로, 1개씩 움직이는 BFS + 중복된 케이스를 세지 않도록 검사

import heapq
from typing import *


class FractionPair:
    def __init__(
        self,
        numeratorIndex: int,
        numerator: int,
        denominatorIndex: int,
        denominator: int,
    ):
        self.numeratorIndex = numeratorIndex
        self.numerator = numerator
        self.denominatorIndex = denominatorIndex
        self.denominator = denominator

    def __lt__(self, other) -> bool:
        return (self.numerator / self.denominator) < (
            other.numerator / other.denominator
        )


class Solution:
    def kthSmallestPrimeFraction(self, arr: List[int], k: int) -> List[int]:
        visited, pq = set(), []
        heapq.heappush(pq, FractionPair(0, arr[0], len(arr) - 1, arr[-1]))
        visited.add((0, len(arr) - 1))

        while k > 1:
            n, d = pq[0].numeratorIndex, pq[0].denominatorIndex
            heapq.heappop(pq)

            if (n + 1, d) not in visited:
                heapq.heappush(pq, FractionPair(n + 1, arr[n + 1], d, arr[d]))
                visited.add((n + 1, d))
            if (n, d - 1) not in visited:
                heapq.heappush(pq, FractionPair(n, arr[n], d - 1, arr[d - 1]))
                visited.add((n, d - 1))

            k -= 1

        return [pq[0].numerator, pq[0].denominator]

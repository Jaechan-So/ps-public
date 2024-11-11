# 1231. Divide Chocolate
# https://leetcode.com/problems/divide-chocolate/description

# 1. Parametric Search
# min(sweetness) ~ sum(sweetness) 사이에서 Parametric Search

from typing import *

class Solution:
    def maximizeSweetness(self, sweetness: List[int], k: int) -> int:
        left, right = min(sweetness), (sum(sweetness) // (k + 1)) + 1

        while left < right:
            minPieceSweetness = (left + right) // 2

            if not self.isDecomposable(sweetness, k, minPieceSweetness):
                right = minPieceSweetness
            else:
                left = minPieceSweetness + 1

        return left - 1

    def isDecomposable(self, sweetness: List[int], k: int, minPieceSweetness: int) -> bool:
        totalSweetness = 0
        pieceCount = 0

        for s in sweetness:
            if minPieceSweetness <= totalSweetness + s:
                totalSweetness = 0
                pieceCount += 1
            else:
                totalSweetness += s

        return pieceCount >= k + 1

# 948. Bag of Tokens
# https://leetcode.com/problems/bag-of-tokens/description

from typing import *

# Greedy?
# 토큰 값이 크면, face-down / 작으면 face-up
# 약간 Knapsack이랑 유사, Greedy가 과연 보장이 될까?
# 정렬한 뒤에 Two Pointer

class Solution:
    def bagOfTokensScore(self, tokens: List[int], power: int) -> int:
        n = len(tokens)
        tokens.sort()
        left, right = 0, n - 1
        maxScore, score = 0, 0

        while left <= right and (power >= tokens[left] or score > 0):
            if power >= tokens[left]:
                power -= tokens[left]
                score += 1
                left += 1
            else:
                power += tokens[right]
                score -= 1
                right -= 1

            maxScore = max(maxScore, score)

        return maxScore

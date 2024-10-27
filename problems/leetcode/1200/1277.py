# 1277. Count Square Submatrices with All Ones
# https://leetcode.com/problems/count-square-submatrices-with-all-ones/description

from typing import *

# 1. Naive Solution with DP
# 한 변의 길이가 k인 정사각형은, 한 변의 길이가 k - 1인 정사각형의 유무를 4번 체크해서 확인할 수 있다.
# 한 변의 최대 길이는 min(m, n)
# 각각의 변 길이에 대해서, 정사각형의 가장 왼쪽 위 좌표를 저장하는 집합을 유지

# 2. Enhanced DP
# dp[i + 1][j + 1] = min(dp[i][j], dp[i + 1][j], dp[i][j + 1]) + 1 if matrix[i][j] == 1 else 0

class Solution:
    def countSquares(self, matrix: List[List[int]]) -> int:
        m, n = len(matrix), len(matrix[0])
        squares = 0
        dp = [0 for _ in range(n + 1)]

        for i in range(m):
            nextDp = [0 for _ in range(n + 1)]

            for j in range(n):
                nextDp[j + 1] = min(dp[j], nextDp[j], dp[j + 1]) + 1 if matrix[i][j] == 1 else 0
                squares += nextDp[j + 1]

            dp = nextDp

        return squares

# 54. Spiral Matrix
# https://leetcode.com/problems/spiral-matrix/description/

from typing import *

class Solution:
    def spiralOrder(self, matrix: List[List[int]]) -> List[int]:
        m, n = len(matrix) - 1, len(matrix[0]) - 1
        x, y = 0, 0

        elements = []
        elements.append(matrix[x][y])

        while m > 0 or n > 0:
            for _ in range(n):
                y += 1
                elements.append(matrix[x][y])

            if m == 0:
                break
            for _ in range(m):
                x += 1
                elements.append(matrix[x][y])
            m -= 1

            if n == 0:
                break
            for _ in range(n):
                y -= 1
                elements.append(matrix[x][y])
            n -= 1

            if m == 0:
                break
            for _ in range(m):
                x -= 1
                elements.append(matrix[x][y])
            m -= 1

            if n == 0:
                break
            n -= 1
            y += 1
            elements.append(matrix[x][y])

        return elements

# 7. Reverse Integer
# https://leetcode.com/problems/reverse-integer/

class Solution:
    def reverse(self, x: int) -> int:
        result = 0
        neg = 0
        for index, reg in enumerate(list(map(lambda n: int(n) if n != '-' else None, list(str(x))))):
            if reg == None:
                neg = 1
                continue
            result = result + reg * (10 ** (index - neg))
        if result >= 2 ** 31 or result < -(2 ** 31):
            return 0
        return result * (-2*neg + 1)

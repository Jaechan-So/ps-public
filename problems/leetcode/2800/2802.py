# 자리수를 먼저 구한다.
# offset을 구하고, 2로 나눈 나머지를 이용한다.

class Solution:
    def kthLuckyNumber(self, k: int) -> str:
        digits, candidates, currentSum = 1, 2, 0
        while currentSum + candidates < k:
            currentSum += candidates
            candidates *= 2
            digits += 1
        remainder = k - currentSum - 1

        luckyNumber = ""
        for i in range(digits):
            luckyNumber += "4" if remainder % 2 == 0 else "7"
            remainder //= 2

        return luckyNumber[::-1]

# 1545. Find Kth Bit in Nth Binary String
# https://leetcode.com/problems/find-kth-bit-in-nth-binary-string/description

# 1. s_n의 길이를 2l + 1이라고 할 때, k == l + 1이면 무조건 1.
# 2. k < l + 1이면, s_(n - 1)의 k와 동일.
# 3. k > l + 1이면, reverse(invert(s_(n - 1)))의 k와 동일. 즉, invert(s_(n - 1))의 (2l + 1 + 1 - k) 번째와 동일.
# 4. l_n = 2 * l_(n - 1) + 1

# Recursive를 Iteration으로 바꾸기 가능

class Solution:
    def findKthBit(self, n: int, k: int) -> str:
        l = (1 << n) - 1
        flipCount = 0

        while k > 1:
            if k == 1 + ((l - 1) // 2):
                return "1" if flipCount % 2 == 0 else "0"

            if k > (l - 1) // 2:
                k = l + 1 - k
                flipCount += 1

            n -= 1
            l = (1 << n) - 1

        return "0" if flipCount % 2 == 0 else "1"

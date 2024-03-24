# 878. Nth Magical Number
# https://leetcode.com/problems/nth-magical-number/description/

# 임의의 수 x에 대해서, (x / a) + (x / b) - (x / lcm(a, b)) = n인 가장 작은 x?
# a = g * x, b = g * y, lcm(a, b) = g * x * y ===> x + y - 1
# 1. q = (n / (x + y - 1)) 을 구한다. 그럼 일단 q * g * x * y 만큼의 수에 해당하는 블록이 지나감
# 2. 블록 내에서의 패턴은 정해져 있고, 우리는 r = (n % (x + y - 1)) 을 알고는 있으므로 패턴에서 찾아내면 됨
# 3. Binary Search?


class Solution:
    def nthMagicalNumber(self, n: int, a: int, b: int) -> int:
        mod = int(1e9 + 7)

        def gcd(x: int, y: int) -> int:
            x_div = set()

            for div in range(2, x + 1):
                if x % div == 0:
                    x_div.add(div)

            common_div = 1
            for div in range(2, y + 1):
                if y % div == 0 and div in x_div:
                    common_div = div

            return common_div

        g = gcd(a, b)
        x, y = a // g, b // g
        q, r = n // (x + y - 1), n % (x + y - 1)

        start, end = 0, g * x * y - 1
        while start < end:
            mid = (start + end) // 2

            if (mid // a) + (mid // b) < r:
                start = mid + 1
            else:
                end = mid

        return (q * g * x * y + end) % mod

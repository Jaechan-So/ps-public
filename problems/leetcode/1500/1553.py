# 1553. Minimum Number of Days to Eat N Oranges
# https://leetcode.com/problems/minimum-number-of-days-to-eat-n-oranges/description

# 1. Naive Solution
# BFS + DP를 이용해서 탐색한다.

from collections import deque

class Solution:
    def minDays(self, n: int) -> int:
        memo = set()

        # q: (number, count)
        q = deque()
        q.append((n, 0))

        while q:
            num, count = q.popleft()

            if num == 1:
                return count + 1

            if num - 1 not in memo:
                memo.add(num - 1)
                q.append((num - 1, count + 1))
            if num % 2 == 0 and num // 2 not in memo:
                memo.add(num // 2)
                q.append((num // 2, count + 1))
            if num % 3 == 0 and num // 3 not in memo:
                memo.add(num // 3)
                q.append((num // 3, count + 1))

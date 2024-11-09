# 22. Generate Parentheses
# https://leetcode.com/problems/generate-parentheses/description/

from collections import deque
from typing import *

class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        answer = []

        q = deque() # (string, number of opening, number of closing)
        q.append(("", 0, 0))

        while q:
            s, left, right = q.popleft()

            if len(s) == 2 * n:
                answer.append(s)
                continue

            if left < n:
                q.append((s + "(", left + 1, right))
            if right < left:
                q.append((s + ")", left, right + 1))

        return answer

# 739. Daily Temperatures
# https://leetcode.com/problems/daily-temperatures/

from typing import *

class Solution:
    def dailyTemperatures(self, temperatures: List[int]) -> List[int]:
        n = len(temperatures)
        answer = [0 for _ in temperatures]

        hottest = n - 1
        for i in range(n - 2, -1, -1):
            if temperatures[i] >= temperatures[hottest]:
                hottest = i
            else:
                diff = 1
                while temperatures[i + diff] <= temperatures[i]:
                    diff += answer[i + diff]
                answer[i] = diff

        return answer

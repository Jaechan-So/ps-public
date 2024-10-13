# 241. Different Ways to Add Parentheses
# https://leetcode.com/problems/different-ways-to-add-parentheses/description

from typing import *

# Recursion + DP

class Solution:
    def __init__(self):
        self.memo = dict()

    def diffWaysToCompute(self, expression: str) -> List[int]:
        if expression in self.memo:
            return self.memo[expression]

        if len(expression) == 0:
            return []

        digitOnly = True
        results = []
        for i, ch in enumerate(expression):
            if ch in ["+", "-", "*"]:
                digitOnly = False
                left, right = self.diffWaysToCompute(expression[:i]), self.diffWaysToCompute(expression[i + 1:])

                for l in left:
                    for r in right:
                        results.append(
                            l + r if ch == "+" else
                            l - r if ch == "-" else
                            l * r
                        )

        if digitOnly:
            results = [int(expression)]
        self.memo[expression] = results
        return self.memo[expression]

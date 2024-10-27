# 32. Longest Valid Parentheses
# https://leetcode.com/problems/longest-valid-parentheses/description/

class Solution:
    def longestValidParentheses(self, s: str) -> int:
        maxLen = 0
        left = right = 0

        for ch in s:
            if ch == "(":
                left += 1
            else:
                right += 1

            if left == right:
                maxLen = max(maxLen, 2 * left)
            elif right > left:
                left = right = 0

        left = right = 0

        for ch in s[::-1]:
            if ch == "(":
                left += 1
            else:
                right += 1

            if left == right:
                maxLen = max(maxLen, 2 * left)
            elif left > right:
                left = right = 0

        return maxLen

# 2914. Minimum Number of Changes to Make Binary String Beautiful
# https://leetcode.com/problems/minimum-number-of-changes-to-make-binary-string-beautiful/description

class Solution:
    def minChanges(self, s: str) -> int:
        n = len(s)

        changes = 0
        for i in range(n // 2):
            changes += (1 if s[2 * i] != s[2 * i + 1] else 0)

        return changes

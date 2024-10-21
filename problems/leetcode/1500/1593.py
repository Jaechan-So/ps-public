# 1593. Split a String Into the Max Number of Unique Substrings
# https://leetcode.com/problems/split-a-string-into-the-max-number-of-unique-substrings/description

# Backtracking?

class Solution:
    def __init__(self):
        self.maxSplits = 0

    def maxUniqueSplit(self, s: str) -> int:
        currentSubstrs = set()
        self.maxUniqueSplitWithCurrentSubstrs(s, currentSubstrs)
        return self.maxSplits

    def maxUniqueSplitWithCurrentSubstrs(self, s: str, currentSubstrs: set[str]) -> None:
        if len(s) == 0:
            self.maxSplits = max(self.maxSplits, len(currentSubstrs))
            return

        if len(currentSubstrs) + len(s) <= self.maxSplits:
            return

        for i in range(len(s)):
            if s[:i + 1] not in currentSubstrs:
                currentSubstrs.add(s[:i + 1])
                self.maxUniqueSplitWithCurrentSubstrs(s[i + 1:], currentSubstrs)
                currentSubstrs.remove(s[:i + 1])

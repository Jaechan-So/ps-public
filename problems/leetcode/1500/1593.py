# 1593. Split a String Into the Max Number of Unique Substrings
# https://leetcode.com/problems/split-a-string-into-the-max-number-of-unique-substrings/description

# Backtracking?

class Solution:
    def maxUniqueSplit(self, s: str) -> int:
        currentSubstrs = set()
        return self.maxUniqueSplitWithCurrentSubstrs(s, currentSubstrs)

    def maxUniqueSplitWithCurrentSubstrs(self, s: str, currentSubstrs: set[str]) -> int:
        if len(s) == 0:
            return len(currentSubstrs)

        maxSplits = 0
        for i in range(len(s)):
            if s[:i + 1] not in currentSubstrs:
                currentSubstrs.add(s[:i + 1])
                maxSplits = max(maxSplits, self.maxUniqueSplitWithCurrentSubstrs(s[i + 1:], currentSubstrs))
                currentSubstrs.remove(s[:i + 1])

        return maxSplits

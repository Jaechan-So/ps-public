# 1957. Delete Characters to Make Fancy String
# https://leetcode.com/problems/delete-characters-to-make-fancy-string/description

class Solution:
    def makeFancyString(self, s: str) -> str:
        n = len(s)
        fancyS = ""

        for i in range(n):
            if len(fancyS) >= 2 and s[i] == fancyS[-1] and s[i] == fancyS[-2]:
                continue
            fancyS += s[i]

        return fancyS

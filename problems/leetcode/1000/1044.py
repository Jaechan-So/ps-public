# 1044. Longest Duplicate Substring
# https://leetcode.com/problems/longest-duplicate-substring/description

# Binary Search로 문자열의 길이 정하기
# 문자열의 길이가 정해지면, 순회하면서 해당 substring이 있는지 체크

class Solution:
    def longestDupSubstring(self, s: str) -> str:
        n = len(s)
        start, end = 1, n

        def getDuplicate(k: int) -> str:
            if k == 0:
                return ""

            exists = set()

            for i in range(0, n - k + 1):
                sub = s[i:i + k]
                if sub in exists:
                    return sub
                exists.add(sub)

            return ""

        while start < end:
            mid = (start + end) // 2
            duplicate = getDuplicate(mid)

            if len(duplicate) == mid:
                start = mid + 1
            else:
                end = mid

        return getDuplicate(end - 1)

# 3. Longest Substring Without Repeating Characters
# https://leetcode.com/problems/longest-substring-without-repeating-characters/description

# 1. Sliding Window + Hash Map
# 각 문자별로 등장하는 위치를 확인해서 미리 저장해둠.
# 중복되는 문자가 들어왔을 경우, 먼저 등장한 문자의 위치 + 1까지 window를 이동.
# T(n), S(n)

class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        if not s:
            return 0

        n = len(s)
        charToIndices = dict()
        maxLen = 1

        left = 0
        for right in range(n):
            if s[right] in charToIndices:
                left = max(left, charToIndices[s[right]] + 1)
            charToIndices[s[right]] = right

            maxLen = max(maxLen, right - left + 1)

        return maxLen

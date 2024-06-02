# 926. Flip String to Monotone Increasing
# https://leetcode.com/problems/flip-string-to-monotone-increasing/description/

# 1. Naive Solution
# 1의 시작 위치를 기준으로, 왼쪽의 1 개수와 오른쪽의 0 개수를 합하면 총 flip 개수

# 2. Improved Naive Solution
# 처음에 오른쪽의 0 개수를 전부 세놓고, 하나씩 움직이면서 개수를 조정


class Solution:
    def minFlipsMonoIncr(self, s: str) -> int:
        n = len(s)
        flip = sum([1 if ch == "0" else 0 for ch in s])
        minFlip = flip

        for i, ch in enumerate(s):
            if ch == "1":
                flip += 1
            else:
                flip -= 1

            minFlip = min(minFlip, flip)

        return minFlip

# 2193. Minimum Number of Moves to Make Palindrome
# https://leetcode.com/problems/minimum-number-of-moves-to-make-palindrome/description

# 1. Naive Solution
# 가능한 모든 경우의 수를 따진다. BFS + visited set

# 2. Greedy?
# 가장 바깥 글자를 먼저 같게 만들고
# 그 안의 바깥 글자를 같게 만들고
# ...
# 이 때 후보가 될 수 있는 것은 개수가 짝수인 경우에만 해당한다. (1개인 경우는 무조건 중앙으로 가야 함)
# 이 때 같게 만들 대상은 현재 상태에서 가장 적은 이동으로 구성할 수 있는 케이스를 고려한다.

from collections import *

class Solution:
    def minMovesToMakePalindrome(self, s: str) -> int:
        n = len(s)
        pairs = (n - 1) // 2

        totalMoves = 0
        for p in range(pairs):
            charToIndices = dict() # (str, deque(int))
            for i, ch in enumerate(s):
                if ch not in charToIndices:
                    charToIndices[ch] = deque()
                charToIndices[ch].append(i)

            minMoveCh, minMoves = None, None
            for ch, indices in charToIndices.items():
                move = indices[0] + (n - 1 - 2 * p - indices[-1])
                if minMoveCh is None or move < minMoves:
                    minMoveCh = ch
                    minMoves = move

            totalMoves += minMoves
            s = s[:charToIndices[minMoveCh][0]] + s[charToIndices[minMoveCh][0] + 1:charToIndices[minMoveCh][-1]] + s[charToIndices[minMoveCh][-1] + 1:]

        return totalMoves

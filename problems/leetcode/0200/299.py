# 299. Bulls and Cows
# https://leetcode.com/problems/bulls-and-cows/description

from collections import defaultdict

class Solution:
    def getHint(self, secret: str, guess: str) -> str:
        n = len(secret)

        bulls, cows = 0, 0
        secretUnmatched, guessUnmatched = defaultdict(int), defaultdict(int)
        for i in range(n):
            if secret[i] == guess[i]:
                bulls += 1
            else:
                secretUnmatched[secret[i]] += 1
                guessUnmatched[guess[i]] += 1

        for digit in secretUnmatched.keys():
            cows += min(secretUnmatched[digit], guessUnmatched[digit])

        return f"{bulls}A{cows}B"

# 72. Edit Distance
# https://leetcode.com/problems/edit-distance/description

# 1. DP
# 같은 경우, 그냥 넘어감
# 다른 경우
# Insert하고 word2만 -1 // Replace하고 word1, word2 모두 -1 // Delete하고 word1만 -1

class Solution:
    def minDistance(self, word1: str, word2: str) -> int:
        n1, n2 = len(word1), len(word2)
        memo = [i for i in range(n2 + 1)]

        for i in range(1, n1 + 1):
            newMemo = [-1 for _ in range(n2 + 1)]
            newMemo[0] = i

            for j in range(1, n2 + 1):
                if word1[i - 1] == word2[j - 1]:
                    newMemo[j] = memo[j - 1]
                else:
                    newMemo[j] = 1 + min(newMemo[j - 1], memo[j - 1], memo[j])

            memo = newMemo

        return memo[n2]

# 2490. Circular Sentence
# https://leetcode.com/problems/circular-sentence/description

class Solution:
    def isCircularSentence(self, sentence: str) -> bool:
        words = sentence.split()
        n = len(words)

        circular = words[-1][-1] == words[0][0]
        for i in range(n - 1):
            circular = circular and words[i][-1] == words[i + 1][0]

        return circular

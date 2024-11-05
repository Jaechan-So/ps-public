# 1813. Sentence Similarity III
# https://leetcode.com/problems/sentence-similarity-iii/description

class Solution:
    def areSentencesSimilar(self, sentence1: str, sentence2: str) -> bool:
        words1, words2 = sentence1.split(" "), sentence2.split(" ")
        if len(words1) < len(words2):
            words1, words2 = words2, words1

        n1, n2 = len(words1), len(words2)
        start, end1, end2 = 0, n1 - 1, n2 - 1

        while start < n2 and words1[start] == words2[start]:
            start += 1

        while end2 >= 0 and words1[end1] == words2[end2]:
            end1 -= 1
            end2 -= 1

        return end2 < start

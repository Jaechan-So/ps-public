# 336. Palindrome Pairs
# https://leetcode.com/problems/palindrome-pairs/description/

from typing import *

# 1. Brute Force
# 모든 경우의 수를 찾고, 연결된 단어가 Palindrome인지 검사
# O(2 * (n - 1) * s)

# 2. 개선
# 각 단어가 앞에 위치한다고 고정했을 때, 뒤에 나와서 Palindrome이 가능한 단어는
# 앞 단어의 앞 일부분을 뒤로 뒤집음 + 뒤 일부분이 Palindrome
# 뒤 단어의 앞 일부분이 Palindrome + 뒤 일부분이 앞 단어와 동일
# 각 단어의 뒷 부분이 Palindrome이 되는지 미리 조사

# 3. (Editorial) Hash Map
# 2번의 아이디어를 이용한다.
# 모든 단어를 Hash Map에 넣는다. (word, index)
# 각 word마다 돌아가면서, prefix 혹은 suffix가 Palindrome이면서 나머지 부분이 Hash Map 안에 있는지를 체크한다.
# Palindrome인지 체크하는 방식은, 그냥 reverse string이 원래 string과 동일한지를 확인하면 된다.

class Solution:
    def palindromePairs(self, words: List[str]) -> List[List[int]]:
        wordToIndex = dict({ word: i for i, word in enumerate(words) })
        pairs = []

        for i, word in enumerate(words):
            n = len(word)

            if word == word[::-1] and "" in wordToIndex:
                j = wordToIndex[""]
                if i != j:
                    pairs += [[i, j], [j, i]]

            if word[::-1] in wordToIndex:
                j = wordToIndex[word[::-1]]
                if i != j:
                    pairs.append([i, j])

            for j in range(1, n):
                if word[:j] == word[j - 1::-1] and word[:j - 1:-1] in wordToIndex:
                    k = wordToIndex[word[:j - 1:-1]]
                    if i != k:
                        pairs.append([k, i])

            for j in range(n - 1, 0, -1):
                if word[j:] == word[:j - 1:-1] and word[j - 1::-1] in wordToIndex:
                    k = wordToIndex[word[j - 1::-1]]
                    if i != k:
                        pairs.append([i, k])

        return pairs

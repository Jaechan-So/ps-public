# 1048. Longest String Chain
# https://leetcode.com/problems/longest-string-chain/description

class Solution:
    def longestStrChain(self, words: List[str]) -> int:
        nextWordCandidates = defaultdict(list[int])

        for i in range(0, len(words)):
            for j in range(i + 1, len(words)):
                x, y = i, j
                if abs(len(words[x]) - len(words[y])) != 1:
                    continue

                if len(words[x]) > len(words[y]):
                    x, y = y, x

                k = 0
                while k < len(words[x]) and words[x][k] == words[y][k]:
                    k += 1

                if k == len(words[x]) or words[x][k:] == words[y][k + 1:]:
                    nextWordCandidates[x].append(y)

        cache = dict()
        def traverse(index: int) -> int:
            if index not in cache:
                maxLen = 1
                for candidate in nextWordCandidates[index]:
                    maxLen = max(maxLen, 1 + traverse(candidate))
                cache[index] = maxLen

            return cache[index]

        result = 0
        for i in range(len(words)):
            result = max(result, traverse(i))

        return result

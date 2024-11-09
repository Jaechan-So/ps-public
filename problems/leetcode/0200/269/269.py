# 269. Alien Dictionary
# https://leetcode.com/problems/alien-dictionary/description/

# 1. Naive Solution
# 임의의 두 단어의 첫 번째로 다른 글자가 사전순을 보장한다.
# 글자 간 선후관계를 얻을 수 있으므로, Topological Sort를 써서 전체 선후관계를 생각할 수 있다.

from collections import deque
from typing import *

class Solution:
    def alienOrder(self, words: List[str]) -> str:
        n = len(words)

        indegrees = dict()
        outdegrees = dict()

        for s in words:
            for ch in s:
                if ch not in indegrees and ch not in outdegrees:
                    indegrees[ch] = 0
                    outdegrees[ch] = set()

        for i in range(n):
            for j in range(i + 1, n):
                if len(words[i]) > len(words[j]) and words[i].startswith(words[j]):
                    return ""

                for k in range(min(len(words[i]), len(words[j]))):
                    if words[i][k] != words[j][k]:
                        if words[j][k] not in outdegrees[words[i][k]]:
                            indegrees[words[j][k]] += 1
                            outdegrees[words[i][k]].add(words[j][k])
                        break

        q = deque()
        for ch, indegree in indegrees.items():
            if indegree == 0:
                q.append(ch)

        rule = ""
        while q:
            ch = q.popleft()
            rule += ch

            for nextChar in outdegrees[ch]:
                indegrees[nextChar] -= 1
                if indegrees[nextChar] == 0:
                    q.append(nextChar)

        return rule if len(rule) == len(indegrees.keys()) else ""

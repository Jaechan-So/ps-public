# 2360. Longest Cycle in a Graph
# https://leetcode.com/problems/longest-cycle-in-a-graph/description

from typing import *

class Solution:
    def longestCycle(self, edges: List[int]) -> int:
        globalVisit, cycleSize = set(), -1

        for src, dst in enumerate(edges):
            if dst == -1 or src in globalVisit:
                continue

            localVisit, currCount, curr = dict(), 0, src
            while curr != -1 and curr not in globalVisit:
                if curr in localVisit:
                    cycleSize = max(cycleSize, currCount - localVisit[curr])
                    for node in localVisit.keys():
                        globalVisit.add(node)
                    break

                localVisit[curr] = currCount
                currCount += 1
                curr = edges[curr]

        return cycleSize

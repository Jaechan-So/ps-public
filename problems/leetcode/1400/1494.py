# 1494. Parallel Courses II
# https://leetcode.com/problems/parallel-courses-ii/description/

# 모든 상태를 탐색해야 함
# 이 때, 이미 수강한 과목과 그렇지 않은 노드를 비트로 저장
# 현재까지 수강한 과목과, 다음 과목으로 가능한 과목의 선수과목을 비트 대조해서 조건을 만족하면 수강이 가능

from itertools import combinations
from typing import *

class Solution:
    def minNumberOfSemesters(self, n: int, relations: List[List[int]], k: int) -> int:
        self.n, self.k, self.memo = n, k, dict()

        inDegrees, self.outDegrees = [0 for _ in range(n + 1)], [[] for _ in range(n + 1)]
        for prevCourse, nextCourse in relations:
            inDegrees[nextCourse] += 1
            self.outDegrees[prevCourse].append(nextCourse)

        return self.traverseStates(inDegrees, ((1 << n) - 1) << 1)

    def traverseStates(self, inDegrees: List[int], mask: int) -> int:
        key = str((inDegrees, mask))
        if key in self.memo:
            return self.memo[key]

        if not mask:
            return 0

        self.memo[key] = float("inf")

        candidates = [i for i in range(1, self.n + 1) if mask & (1 << i) and inDegrees[i] == 0]
        for targets in combinations(candidates, min(len(candidates), self.k)):
            nextInDegrees, nextMask = list(inDegrees), mask

            for semester in targets:
                nextMask ^= (1 << semester)

                for nextSemester in self.outDegrees[semester]:
                    nextInDegrees[nextSemester] -= 1

            self.memo[key] = min(self.memo[key], 1 + self.traverseStates(nextInDegrees, nextMask))

        return self.memo[key]

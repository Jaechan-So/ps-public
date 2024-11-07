# 210. Course Schedule II
# https://leetcode.com/problems/course-schedule-ii/description/

from collections import defaultdict, deque
from typing import *

class Solution:
    def findOrder(self, numCourses: int, prerequisites: List[List[int]]) -> List[int]:
        indegrees = [0 for _ in range(numCourses)]
        outdegrees = defaultdict(set[int])

        for src, dst in prerequisites:
            indegrees[src] += 1
            outdegrees[dst].add(src)

        q = deque()
        for i in range(numCourses):
            if indegrees[i] == 0:
                q.append(i)

        courseOrder = []
        while q:
            currentCourses = list(q)
            while q:
                q.popleft()
            courseOrder += currentCourses

            for course in currentCourses:
                for nextCourse in outdegrees[course]:
                    indegrees[nextCourse] -= 1
                    if indegrees[nextCourse] == 0:
                        q.append(nextCourse)

        return courseOrder if len(courseOrder) == numCourses else []

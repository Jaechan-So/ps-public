# 1723. Find Minimum Time to Finish All Jobs
# https://leetcode.com/problems/find-minimum-time-to-finish-all-jobs/description

from typing import *

class Solution:
    def minimumTimeRequired(self, jobs: List[int], k: int) -> int:
        self.minMaxTime = sum(jobs)
        self.jobs = jobs
        self.k = k
        self.workerTimes = []

        self.traverse(0)

        return self.minMaxTime

    def traverse(self, index: int) -> None:
        if index == len(self.jobs):
            self.minMaxTime = min(self.minMaxTime, max(self.workerTimes))
            return

        currentJob = self.jobs[index]

        seen = set()
        for i in range(len(self.workerTimes)):
            if self.workerTimes[i] in seen:
                continue
            if self.workerTimes[i] + currentJob > self.minMaxTime:
                continue
            seen.add(self.workerTimes[i])
            self.workerTimes[i] += currentJob
            self.traverse(index + 1)
            self.workerTimes[i] -= currentJob

        if len(self.workerTimes) < self.k:
            self.workerTimes.append(currentJob)
            self.traverse(index + 1)
            self.workerTimes.pop()

# 857. Minimum Cost to Hire K Workers
# https://leetcode.com/problems/minimum-cost-to-hire-k-workers/description

# k명의 worker를 이미 골랐다고 가정하면, 어떤 (wage / quality) 값이 정해져야 한다.
# 해당 값에 각 worker별 quality를 곱한 값이 각자의 wage를 넘기만 하면 된다.
# 즉, (wage / quality) 값은 골라진 worker들의 값들 중 최댓값이 될 것이다.
# min(max(wage / quality) * (sum(quality)))
# max(wage / quality)를 고정한다면, sum(quality)는 그 중 최소로 선택할 수 있다. 이 때 sum(quality)에 반드시 고정된 원소가 들어가 있어야 한다.
# quality를 오름차순 정렬하되, 특정 원소를 쉽게 뺄 수 있어야 한다.

from typing import *

class Solution:
    def mincostToHireWorkers(self, quality: List[int], wage: List[int], k: int) -> float:
        n = len(quality)

        workers = [(quality[i], wage[i], i) for i in range(n)]
        workers.sort()

        wagePerQualities = [(workers[i][1] / workers[i][0], i) for i in range(n)]
        wagePerQualities.sort(reverse=True)

        minCost = float("inf")
        left, right = 0, k - 1 # left: wagePerQualities, right: workers
        qualitySum = sum([q for q, _, _ in workers[:k]])
        removedIndices = set()

        while right < n:
            ratio, i = wagePerQualities[left]
            currentQualitySum = qualitySum

            if i > right:
                currentQualitySum -= workers[right][0]
                currentQualitySum += workers[i][0]

            minCost = min(minCost, ratio * currentQualitySum)

            removedIndices.add(i)
            if i <= right:
                qualitySum -= workers[i][0]

                right += 1
                while right < n and right in removedIndices:
                    right += 1

                if right < n:
                    qualitySum += workers[right][0]

            left += 1

        return minCost

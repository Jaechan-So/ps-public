# 765. Couples Holding Hands
# https://leetcode.com/problems/couples-holding-hands/description

# 1. Naive Solution
# Backtracking
# +) 이미 바로 옆자리인 커플은 건드릴 필요가 없다

# 2. Number of cycles?
# 사이클이 존재하면, 사이클의 원소 개수 - 1번만큼만 움직이면 원하는 상태로 재배치할 수 있다.
# 현재 자리 상태에서, 자신의 이웃 번호를 value로 가지고 자신의 번호가 key인 Hash Map 생성
# DFS로 각 번호에 대해 들어가면서, 이웃의 연인 번호를 계속 타고 들어가면서 Cycle 탐색
# 중복 탐색을 방지하기 위해서 visited Hash Set 이용

from typing import *

class Solution:
    def minSwapsCouples(self, row: List[int]) -> int:
        n = len(row)
        visited = set()

        indices = dict()
        for i in range(n // 2):
            indices[row[2 * i]] = 2 * i
            indices[row[2 * i + 1]] = 2 * i + 1

        swaps = 0
        for i in range(n):
            if i in visited:
                continue

            couples = 0

            curr = i
            while True:
                visited.add(curr)
                neighbor = indices[curr] + 1 if indices[curr] % 2 == 0 else indices[curr] - 1
                curr = row[neighbor] + 1 if row[neighbor] % 2 == 0 else row[neighbor] - 1
                visited.add(row[neighbor])

                couples += 1
                if curr == i:
                    break

            swaps += (couples - 1)

        return swaps

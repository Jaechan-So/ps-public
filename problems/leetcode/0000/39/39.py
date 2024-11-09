# 39. Combination Sum
# https://leetcode.com/problems/combination-sum/description/

# 1. Naive Solution
# 각각의 후보 숫자들을 고를 수 있는 경우의 수가 정해짐
# 각 경우에 따라 후속 숫자들을 고를 수 있는 경우의 수가 또 정해짐
# 반복해서 Backtracking으로 모든 경우의 수를 확인

from typing import *

class Solution:
    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
        self.combinations = []
        self.currentCombination = []

        self.traverseCases(candidates, 0, target)

        return self.combinations

    def traverseCases(self, candidates: List[int], index: int, target: int) -> None:
        if target == 0:
            self.combinations.append(list(self.currentCombination))
            return

        if index == len(candidates):
            return

        self.traverseCases(candidates, index + 1, target)
        for i in range(target // candidates[index]):
            self.currentCombination.append(candidates[index])
            self.traverseCases(candidates, index + 1, target - (i + 1) * candidates[index])

        for _ in range(target // candidates[index]):
            self.currentCombination.pop()

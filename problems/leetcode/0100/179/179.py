# 179. Largest Number
# https://leetcode.com/problems/largest-number/description/

# 두 수의 비교
# 두 수를 a, b라고 했을 때, ab가 더 큰지 ba가 더 큰지 비교하면 된다.

from typing import *

class Node:
    def __init__(self, value: int):
        self.value = value

    def __lt__(self, other):
        return int(str(self.value) + str(other.value)) < int(str(other.value) + str(self.value))

class Solution:
    def largestNumber(self, nums: List[int]) -> str:
        answer = "".join([str(node.value) for node in sorted([Node(num) for num in nums], reverse=True)])

        first = 0
        while first < len(answer) - 1 and answer[first] == "0":
            first += 1

        return answer[first:]

# 895. Maximum Frequency Stack
# https://leetcode.com/problems/maximum-frequency-stack/description/

from collections import defaultdict
from typing import *

# 1. (val, frequency)를 저장하는 자료구조 필요
# 2. (frequency, Linked List of values) 자료구조 필요
# 3. 현재 Maximum Frequency 필요

class ListNode:

    def __init__(self, val: int, left: Optional["ListNode"] = None, right: Optional["ListNode"] = None):
        self.val = val
        self.left = left
        self.right = right

class FreqStack:

    def __init__(self):
        self.valToFrequency = defaultdict(int) # (value, frequency)
        self.frequencyToListNodes = dict()
        self.maxFrequency = 0

    # push
    # 1. frequency 하나 증가
    # 2. 2번 자료구조에 증가된 frequency에 하나 추가
    # 3. 필요한 경우, maxFrequency 증가
    def push(self, val: int) -> None:
        self.valToFrequency[val] += 1
        freq = self.valToFrequency[val]

        node = ListNode(val)
        if freq in self.frequencyToListNodes:
            node.right = self.frequencyToListNodes[freq]
            self.frequencyToListNodes[freq].left = node
        self.frequencyToListNodes[freq] = node

        self.maxFrequency = max(self.maxFrequency, self.valToFrequency[val])

    # pop
    # 1. maxFrequency 확인 후 해당 Linked List에서 하나 제외.
    # 2. frequencyToListNodes 클린업
    def pop(self) -> int:
        val = self.frequencyToListNodes[self.maxFrequency].val
        self.valToFrequency[val] -= 1

        node = self.frequencyToListNodes[self.maxFrequency]
        if node.right:
            node.right.left = None
        self.frequencyToListNodes[self.maxFrequency] = self.frequencyToListNodes[self.maxFrequency].right

        while self.maxFrequency > 0 and self.frequencyToListNodes[self.maxFrequency] is None:
            del self.frequencyToListNodes[self.maxFrequency]
            self.maxFrequency -= 1

        return val


# Your FreqStack object will be instantiated and called as such:
# obj = FreqStack()
# obj.push(val)
# param_2 = obj.pop()

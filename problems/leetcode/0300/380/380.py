# 380. Insert Delete GetRandom O(1)
# https://leetcode.com/problems/insert-delete-getrandom-o1/description/

from math import floor
import random

class RandomizedSet:

    def __init__(self):
        self.arr = []
        self.map = dict()

    def insert(self, val: int) -> bool:
        if val in self.map:
            return False

        self.map[val] = len(self.arr)
        self.arr.append(val)
        return True

    def remove(self, val: int) -> bool:
        if val not in self.map:
            return False

        targetIndex, lastIndex = self.map[val], len(self.arr) - 1
        self.map[self.arr[-1]] = targetIndex
        self.arr[targetIndex], self.arr[lastIndex] = self.arr[lastIndex], self.arr[targetIndex]
        self.arr.pop()
        del self.map[val]
        return True

    def getRandom(self) -> int:
        index = floor(random.randrange(0, len(self.arr)))
        return self.arr[index]


# Your RandomizedSet object will be instantiated and called as such:
# obj = RandomizedSet()
# param_1 = obj.insert(val)
# param_2 = obj.remove(val)
# param_3 = obj.getRandom()

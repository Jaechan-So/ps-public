# 2349. Design a Number Container System
# https://leetcode.com/problems/design-a-number-container-system/description

from collections import defaultdict, heapq

# Priority Queue Lazy Update

class NumberContainers:

    def __init__(self):
        self.indexToVal = dict()
        self.valToIndices = defaultdict(list)

    def cleanup(self, number: int) -> None:
        while len(self.valToIndices[number]) > 0 and number != self.indexToVal[self.valToIndices[number][0]]:
            heapq.heappop(self.valToIndices[number])

    def change(self, index: int, number: int) -> None:
        prevVal = self.indexToVal[index] if index in self.indexToVal else None
        self.indexToVal[index] = number
        heapq.heappush(self.valToIndices[number], index)

        self.cleanup(number)
        if prevVal:
            self.cleanup(prevVal)

    def find(self, number: int) -> int:
        return self.valToIndices[number][0] if len(self.valToIndices[number]) > 0 else -1


# Your NumberContainers object will be instantiated and called as such:
# obj = NumberContainers()
# obj.change(index,number)
# param_2 = obj.find(number)

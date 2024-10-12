# 155. Min Stack
# https://leetcode.com/problems/min-stack/description/

class MinStack:

    def __init__(self):
        self.valAndCumulativeMins = []

    def push(self, val: int) -> None:
        cumulativeMin = val
        if len(self.valAndCumulativeMins) > 0:
            cumulativeMin = min(cumulativeMin, self.valAndCumulativeMins[-1][1])
        self.valAndCumulativeMins.append((val, cumulativeMin))

    def pop(self) -> None:
        self.valAndCumulativeMins.pop()

    def top(self) -> int:
        return self.valAndCumulativeMins[-1][0]

    def getMin(self) -> int:
        return self.valAndCumulativeMins[-1][1]


# Your MinStack object will be instantiated and called as such:
# obj = MinStack()
# obj.push(val)
# obj.pop()
# param_3 = obj.top()
# param_4 = obj.getMin()

# 1381. Design a Stack With Increment Operation
# https://leetcode.com/problems/design-a-stack-with-increment-operation/description/

class CustomStack:

    def __init__(self, maxSize: int):
        self.maxSize = maxSize
        self.stack = []
        self.incr = []

    def push(self, x: int) -> None:
        if len(self.stack) == self.maxSize:
            return

        self.stack.append(x)
        self.incr.append(0)

    def pop(self) -> int:
        if len(self.stack) == 0:
            return -1

        val = self.stack[-1] + self.incr[-1]
        if len(self.incr) > 1:
            self.incr[-2] += self.incr[-1]
        self.stack.pop()
        self.incr.pop()
        return val

    def increment(self, k: int, val: int) -> None:
        last = min(k, len(self.incr)) - 1
        if last >= 0:
            self.incr[last] += val


# Your CustomStack object will be instantiated and called as such:
# obj = CustomStack(maxSize)
# obj.push(x)
# param_2 = obj.pop()
# obj.increment(k,val)

from collections import *
from typing import *

# 뱀의 좌표는 deque과 set으로 구현

class SnakeGame:

    def __init__(self, width: int, height: int, food: List[List[int]]):
        self.dr = { "U": -1 ,"D": 1, "L": 0, "R": 0 }
        self.dc = { "U": 0, "D": 0, "L": -1 ,"R": 1 }

        self.width = width
        self.height = height

        self.food = food
        self.foodIndex = 0

        self.coordinateDeque = deque()
        self.coordinateSet = set()

        self.coordinateDeque.append((0, 0))
        self.coordinateSet.add((0, 0))

    def move(self, direction: str) -> int:
        r, c = self.coordinateDeque[-1]
        nextR, nextC = r + self.dr[direction], c + self.dc[direction]

        if self.foodIndex < len(self.food) and nextR == self.food[self.foodIndex][0] and nextC == self.food[self.foodIndex][1]:
            self.foodIndex += 1
        else:
            oldR, oldC = self.coordinateDeque.popleft()
            self.coordinateSet.remove((oldR, oldC))

        if not 0 <= nextR < self.height or not 0 <= nextC < self.width or (nextR, nextC) in self.coordinateSet:
            return -1

        self.coordinateDeque.append((nextR, nextC))
        self.coordinateSet.add((nextR, nextC))

        return self.foodIndex

# Your SnakeGame object will be instantiated and called as such:
# obj = SnakeGame(width, height, food)
# param_1 = obj.move(direction)

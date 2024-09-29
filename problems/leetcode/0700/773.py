# 773. Sliding Puzzle
# https://leetcode.com/problems/sliding-puzzle/description/

from collections import deque
from typing import *

# BFS?
# q(deque[state])
# visited(set[state])

class Solution:
    def __init__(self):
        self.dx = [1, -1, 0, 0]
        self.dy = [0, 0, 1, -1]

    def slidingPuzzle(self, board: List[List[int]]) -> int:
        solved = [[1,2,3],[4,5,0]]
        visited = dict()
        q = deque()

        visited[str(board)] = 0
        q.append((board, 0))

        while len(q) > 0:
            state, move = q.popleft()

            if str(state) == str(solved):
                return move

            for nextState in self.getPossibleStates(state):
                if str(nextState) not in visited:
                    visited[str(nextState)] = move + 1
                    q.append((nextState, move + 1))

        return -1

    def getPossibleStates(self, board: List[List[int]]) -> List[List[List[int]]]:
        x, y = -1, -1

        for i in range(len(board)):
            for j in range(len(board[0])):
                if board[i][j] == 0:
                    x, y = i, j
                    break

        nextStates = []
        for i in range(4):
            nextX, nextY = x + self.dx[i], y + self.dy[i]
            if 0 <= nextX < len(board) and 0 <= nextY < len(board[0]):
                nextState = [[0,0,0],[0,0,0]]
                for j in range(len(board)):
                    for k in range(len(board[0])):
                        nextState[j][k] = board[j][k]
                nextState[x][y] = board[nextX][nextY]
                nextState[nextX][nextY] = board[x][y]
                nextStates.append(nextState)

        return nextStates

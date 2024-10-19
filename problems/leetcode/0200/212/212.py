# 212. Word Search II
# https://leetcode.com/problems/word-search-ii/description/

from typing import *

# 1. words로 Trie 생성
# 2. 칸마다 돌아다니면서 인접한 칸을 확인해서 Trie에 있으면 계속 나아가기
# O(m * n * 3^k)

class TrieNode:
    def __init__(self):
        self.value = None
        self.children = dict()

    def insert(self, s: str) -> None:
        node = self

        for ch in s:
            if ch not in node.children:
                node.children[ch] = TrieNode()
            node = node.children[ch]

        node.value = s

class Solution:
    def __init__(self):
        self.root = TrieNode()
        self.results = set()
        self.deltas = [(1, 0), (-1, 0), (0, 1), (0, -1)]

    def findWords(self, board: List[List[str]], words: List[str]) -> List[str]:
        for word in words:
            self.root.insert(word)

        m, n = len(board), len(board[0])
        for i in range(m):
            for j in range(n):
                visited = set()
                self.traverse(board, m, n, i, j, self.root, visited)

        return list(self.results)

    def traverse(self, board: List[List[str]], m: int, n: int, r: int, c: int, node: TrieNode, visited: set[tuple[int, int]]) -> None:
        if board[r][c] not in node.children.keys():
            return

        nextNode = node.children[board[r][c]]
        if nextNode.value:
            self.results.add(nextNode.value)

        visited.add((r, c))
        for dr, dc in self.deltas:
            nextR, nextC = r + dr, c + dc

            if 0 <= nextR < m and 0 <= nextC < n and (nextR, nextC) not in visited:
                self.traverse(board, m, n, nextR, nextC, nextNode, visited)

        visited.remove((r, c))

# 138. Copy List with Random Pointer
# https://leetcode.com/problems/copy-list-with-random-pointer/description

from typing import *

class Node:
    def __init__(self, x: int, next: 'Node' = None, random: 'Node' = None):
        self.val = int(x)
        self.next = next
        self.random = random

"""
# Definition for a Node.
class Node:
    def __init__(self, x: int, next: 'Node' = None, random: 'Node' = None):
        self.val = int(x)
        self.next = next
        self.random = random
"""

class Solution:
    def copyRandomList(self, head: 'Optional[Node]') -> 'Optional[Node]':
        if not head:
            return None

        node = head
        while node:
            mirror = Node(node.val, node.next)
            node.next = mirror
            node = node.next
            if node:
                node = node.next

        node = head
        while node:
            if node.random:
                node.next.random = node.random.next
            node = node.next
            if node:
                node = node.next

        node = head.next
        while node:
            node.next = node.next.next if node.next else None
            node = node.next

        return head.next


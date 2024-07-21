# 1721. Swapping Nodes in a Linked List
# https://leetcode.com/problems/swapping-nodes-in-a-linked-list/description

# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

from typing import *

class Solution:
    def swapNodes(self, head: Optional[ListNode], k: int) -> Optional[ListNode]:
        if head is None:
            return head

        curr = head
        n = 0
        while curr is not None:
            n += 1
            curr = curr.next

        node1, node2 = head, head
        for i in range(k - 1):
            node1 = node1.next
        for i in range(n - k):
            node2 = node2.next

        node1.val, node2.val = node2.val, node1.val

        return head

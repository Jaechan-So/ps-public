# 19. Remove Nth Node From End of List
# https://leetcode.com/problems/remove-nth-node-from-end-of-list/description/

from typing import *

# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def removeNthFromEnd(self, head: Optional[ListNode], n: int) -> Optional[ListNode]:
        start, curr, end = None, head, head

        for _ in range(n):
            if end:
                end = end.next

        while end:
            end = end.next
            start = curr
            curr = curr.next

        if curr == head:
            return curr.next

        start.next = curr.next
        return head

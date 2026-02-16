# 86. Partition List
# https://leetcode.com/problems/partition-list/description

from typing import *

# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def partition(self, head: Optional[ListNode], x: int) -> Optional[ListNode]:
        lessHead, greaterHead = ListNode(), ListNode()
        lessTail, greaterTail = lessHead, greaterHead

        current = head

        while current:
            if current.val < x:
                lessTail.next = current
                lessTail = lessTail.next
            else:
                greaterTail.next = current
                greaterTail = greaterTail.next
            current = current.next

        lessTail.next = greaterHead.next
        greaterTail.next = None

        return lessHead.next if lessHead.next else greaterHead.next

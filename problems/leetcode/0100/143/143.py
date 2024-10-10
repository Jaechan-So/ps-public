# 143. Reorder List
# https://leetcode.com/problems/reorder-list/description/

from typing import *

# 1. Fast-Slow Two Pointer를 이용해서 Fast가 null일 때 까지 이동하면 Slow는 뒤집히는 리스트의 시작 노드
# 2. 뒤 리스트는 뒤집음
# 3. 뒤집은 리스트와 기존 리스트를 순서대로 이음

# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def reorderList(self, head: Optional[ListNode]) -> None:
        """
        Do not return anything, modify head in-place instead.
        """
        backHead = self.getBackHead(head)
        reversedBackListHead = self.reverseList(backHead)
        self.concatTwoList(head, reversedBackListHead)

    def getBackHead(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if not head:
            return head

        prev, slow, fast = None, head, head
        while fast:
            prev = slow
            slow = slow.next
            fast = fast.next
            if fast:
                fast = fast.next

        prev.next = None
        return slow

    def reverseList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if not head:
            return head

        prev, curr = None, head
        while curr:
            node = curr.next
            curr.next = prev
            prev = curr
            curr = node

        return prev

    def concatTwoList(self, head1: Optional[ListNode], head2: Optional[ListNode]) -> None:
        node1, node2 = head1, head2

        while node1 or node2:
            next1 = node1.next
            node1.next = node2

            next2 = None
            if node2:
                next2 = node2.next
                node2.next = next1


            node1 = next1
            node2 = next2


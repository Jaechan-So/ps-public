# 25. Reverse Nodes in k-Group
# https://leetcode.com/problems/reverse-nodes-in-k-group/description/

from typing import *

# slow, fast pointer - fast pointer가 None이 되지 않을 때 까지 반복
# 1. fast를 k만큼 움직임. 이 때 중간에 None이 되어버리면 전체 반복 중단
# 2. 첫 번째 slow를 prev에 저장
# 3. 첫 번째 slow를 제외한 각 slow마다 reverse
# 4. 마지막 slow의 경우 newHead 또는 prev.next에 할당해야 함

# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def reverseKGroup(self, head: Optional[ListNode], k: int) -> Optional[ListNode]:
        if not head:
            return head

        slow, fast = head, head
        prevEnd, newHead = None, None

        while fast:
            for _ in range(k):
                if not fast:
                    return newHead
                fast = fast.next

            nextEnd = slow

            prev = fast
            for i in range(k):
                temp = slow.next
                slow.next = prev
                prev = slow

                if i < k - 1:
                    slow = temp

            if not newHead:
                newHead = slow
            else:
                prevEnd.next = slow

            slow = fast
            prevEnd = nextEnd

        return newHead

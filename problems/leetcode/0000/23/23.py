# 23. Merge k Sorted Lists
# https://leetcode.com/problems/merge-k-sorted-lists/description/

import heapq
from typing import *


# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def mergeKLists(self, lists: List[Optional[ListNode]]) -> Optional[ListNode]:
        n = len(lists)

        pq = []
        for i in range(n):
            if lists[i]:
                heapq.heappush(pq, (lists[i].val, i))

        mergedList = None
        head = None
        while len(pq) > 0:
            val, index = heapq.heappop(pq)

            if mergedList is None:
                mergedList = ListNode(val)
                head = mergedList
            else:
                tail = ListNode(val)
                mergedList.next = tail
                mergedList = tail

            if lists[index].next:
                lists[index] = lists[index].next
                heapq.heappush(pq, (lists[index].val, index))

        return head

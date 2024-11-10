# 4. Median of Two Sorted Arrays
# https://leetcode.com/problems/median-of-two-sorted-arrays/description/

from typing import *

class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        n1, n2 = len(nums1), len(nums2)
        if n1 > n2:
            return self.findMedianSortedArrays(nums2, nums1)

        start, end = 0, n1
        while start <= end:
            mid1 = (start + end) // 2
            mid2 = ((n1 + n2 + 1) // 2) - mid1

            left1 = nums1[mid1 - 1] if mid1 > 0 else float("-inf")
            right1 = nums1[mid1] if mid1 < n1 else float("inf")
            left2 = nums2[mid2 - 1] if mid2 > 0 else float("-inf")
            right2 = nums2[mid2] if mid2 < n2 else float("inf")

            if left1 <= right2 and left2 <= right1:
                return float(max(left1, left2) + min(right1, right2)) / 2 if (n1 + n2) % 2 == 0 else float(max(left1, left2))
            elif left1 > right2:
                end = mid1
            else:
                start = mid1 + 1

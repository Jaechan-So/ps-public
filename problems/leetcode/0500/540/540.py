# 540. Single Element in a Sorted Array
# https://leetcode.com/problems/single-element-in-a-sorted-array/description

# 1. 전체가 홀수일 때: 가운데 원소가 1개이거나, 개수가 홀수 쪽에 1개 짜리가 존재

class Solution:
    def singleNonDuplicate(self, nums: List[int]) -> int:
        left, right = 0, len(nums) - 1

        while left < right:
            mid = (left + right) // 2

            if nums[mid - 1] != nums[mid] and nums[mid] != nums[mid + 1]:
                return nums[mid]

            sameOnLeft, sameOnRight = 1 if nums[mid - 1] == nums[mid] else 0, 1 if nums[mid] == nums[mid + 1] else 0

            if (((right - left) // 2) - sameOnLeft) % 2 == 1:
                right = max(left, mid - 1 - sameOnLeft)
            else:
                left = min(right, mid + 1 + sameOnRight)

        return nums[left]

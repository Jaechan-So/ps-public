# 259. 3Sum Smaller
# https://leetcode.com/problems/3sum-smaller/description/

# 1. Sort + Binary Search
# 2. Sort + Two Pointer
# 어차피 아무거나 3개 뽑아서 조건을 만족하면 해당하는 인덱스 쌍의 순서는 자동적으로 1개로 결정되므로, 인덱스 순서 조건은 아무 의미 없음.
# 정렬해도 무방
# 인덱스 하나를 고정하면, nums[j] + nums[k] < target - nums[i] 형태로 2개짜리 문제로 변환
# Two Pointer로 조건 만족하면 왼쪽 올리고 만족 안 하면 오른쪽 내려서 개수 세기

class Solution:
    def threeSumSmaller(self, nums: List[int], target: int) -> int:
        result = 0

        nums.sort()

        for i in range(0, len(nums) - 2):
            left, right = i + 1, len(nums) - 1

            while left < right:
                if nums[i] + nums[left] + nums[right] < target:
                    result += (right - left)
                    left += 1
                else:
                    right -= 1

        return result

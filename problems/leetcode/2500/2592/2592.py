# 2592. Maximize Greatness of an Array
# https://leetcode.com/problems/maximize-greatness-of-an-array/description/

# 중복이 없으면, 그냥 1개만 rotate해서 n - 1개가 최대가 됨.
# 중복이 생겼을 때, greatness를 크게 만들 수 있는 방법 접근 필요
# 큰 것부터 해치우는게 유리함. 왜냐하면 큰 수는 더 큰 수로만 해치울 수 있으니까.

# 1,1,1,2,3,3,5

# 1. 원소와 그 개수를 Map에 저장해서 시작
# 2. largerNumberCount: 사용 가능한, 현재 수보다 더 큰 수의 개수. 처음 시작은 가장 큰 수의 개수
# 3. 두 번째로 큰 수부터 시작해서 Map을 역순으로 순회.
# 4. 첫 번째 동작: min(두 번째로 큰 수 개수, largerNumberCount)를 계산, 이 값을 result에 더함. largerNumberCount에서 이 값을 빼줌
# 5. 두 번째 동작: largerNumberCount에 이번 수 개수를 더함
# 6. 위 동작을 모든 수에 대해서 반복

# T(n) = O(nlogn), S(n) = O(n)

# 논리는 같은데 더 쉬운 방법
# 정렬 + Two Pointer

class Solution:
    def maximizeGreatness(self, nums: List[int]) -> int:
        nums.sort(reverse=True)

        i, j = 0, 0
        while j < len(nums) and nums[i] == nums[j]:
            j += 1

        result = 0
        while j < len(nums):
            if nums[i] > nums[j]:
                result += 1
                i += 1
            j += 1

        return result

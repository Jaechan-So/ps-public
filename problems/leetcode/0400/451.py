# 451. Sort Characters By Frequency
# https://leetcode.com/problems/sort-characters-by-frequency

from collections import Counter

# 1. 각 문자의 등장 횟수를 map에 저장하고, 정렬한 뒤 다시 반환. T(nlogn), S(n)
# 2. Bucket Sort로 개선도 가능

class Solution:
    def frequencySort(self, s: str) -> str:
        charToCount = Counter(s)
        maxCount = max(charToCount.values())

        buckets = [[] for _ in range(maxCount + 1)]
        for ch, count in charToCount.items():
            buckets[count].append(ch)

        result = ""
        for count in range(maxCount, -1, -1):
            for ch in buckets[count]:
                result += (ch * count)

        return result

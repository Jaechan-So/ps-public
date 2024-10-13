# 1921. Eliminate Maximum Number of Monsters
# https://leetcode.com/problems/eliminate-maximum-number-of-monsters/description

from math import *
from typing import *

# ceil(dist / speed) 값을 이용해서 시간 순으로 정렬하면 시급한 정도를 알 수 있다.
# 만약 시간 <= index라면, 패배한다.

class Solution:
    def eliminateMaximum(self, dist: List[int], speed: List[int]) -> int:
        n = len(dist)
        reachedTimes = [ceil(dist[i] / speed[i]) for i in range(n)]

        for i, t in enumerate(sorted(reachedTimes)):
            if t <= i:
                return i

        return n

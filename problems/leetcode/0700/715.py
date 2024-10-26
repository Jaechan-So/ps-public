# 715. Range Module
# https://leetcode.com/problems/range-module/description

import bisect

# 1. 탐색해야 하는 점들이 하나의 배열에 같이 있어야 처리가 더 쉬워짐. Range의 왼쪽인지 오른쪽인지는 index로 구분.

class RangeModule:

    def __init__(self):
        self.ranges = []

    def addRange(self, left: int, right: int) -> None:
        start = bisect.bisect_left(self.ranges, left)
        end = bisect.bisect_right(self.ranges, right)

        overlap = []
        if start % 2 == 0:
            overlap.append(left)
        if end % 2 == 0:
            overlap.append(right)
        self.ranges[start:end] = overlap

    def queryRange(self, left: int, right: int) -> bool:
        start = bisect.bisect_right(self.ranges, left)
        end = bisect.bisect_left(self.ranges, right)
        return start == end and end % 2 == 1

    def removeRange(self, left: int, right: int) -> None:
        start = bisect.bisect_left(self.ranges, left)
        end = bisect.bisect_right(self.ranges, right)

        overlap = []
        if start % 2 == 1:
            overlap.append(left)
        if end % 2 == 1:
            overlap.append(right)
        self.ranges[start:end] = overlap


# Your RangeModule object will be instantiated and called as such:
# obj = RangeModule()
# obj.addRange(left,right)
# param_2 = obj.queryRange(left,right)
# obj.removeRange(left,right)

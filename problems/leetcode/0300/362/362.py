# 362. Design Hit Counter
# https://leetcode.com/problems/design-hit-counter/description/

import bisect

# Binary Search
# hits: hit가 일어났을 때의 timestamp를 저장한 배열

class HitCounter:

    def __init__(self):
        self.hits = []

    def hit(self, timestamp: int) -> None:
        self.hits.append(timestamp)

    def getHits(self, timestamp: int) -> int:
        return len(self.hits) - bisect.bisect_left(self.hits, timestamp - 299)


# Your HitCounter object will be instantiated and called as such:
# obj = HitCounter()
# obj.hit(timestamp)
# param_2 = obj.getHits(timestamp)

# 981. Time Based Key-Value Store
# https://leetcode.com/problems/time-based-key-value-store/description/

import bisect
from collections import defaultdict

class TimeMap:

    def __init__(self):
        self.keyToValues = defaultdict(list[str]) # (str, List[str])
        self.keyToTimestamps = defaultdict(list[int]) # (str, List[int])

    def set(self, key: str, value: str, timestamp: int) -> None:
        self.keyToValues[key].append(value)
        self.keyToTimestamps[key].append(timestamp)

    def get(self, key: str, timestamp: int) -> str:
        if not self.keyToTimestamps[key]:
            return ""

        index = bisect.bisect_right(self.keyToTimestamps[key], timestamp) - 1
        return self.keyToValues[key][index] if index >= 0 else ""


# Your TimeMap object will be instantiated and called as such:
# obj = TimeMap()
# obj.set(key,value,timestamp)
# param_2 = obj.get(key,timestamp)

# 146. LRU Cache
# https://leetcode.com/problems/lru-cache/description/

from collections import OrderedDict

# Linked List + Hash Map

class LRUCache:

    def __init__(self, capacity: int):
        self.capacity = capacity
        self.map = OrderedDict()

    def get(self, key: int) -> int:
        if key not in self.map:
            return -1

        self.map.move_to_end(key)
        return self.map[key]

    def put(self, key: int, value: int) -> None:
        if key not in self.map and len(self.map) == self.capacity:
            self.map.popitem(last=False)

        self.map[key] = value
        self.map.move_to_end(key)


# Your LRUCache object will be instantiated and called as such:
# obj = LRUCache(capacity)
# param_1 = obj.get(key)
# obj.put(key,value)

// 146. LRU Cache
// https://leetcode.com/problems/lru-cache/

using namespace std;

#include <map>
#include <queue>

class LRUCache {
public:
  map<int, int> keyValues;
  map<int, int> recentKeyTimestamps;
  queue<pair<int, int>> activeKeyTimestamps;
  int timestamp = 0, keyCapacity = 0;

  LRUCache(int capacity) { keyCapacity = capacity; }

  int get(int key) {
    timestamp++;

    if (keyValues.find(key) != keyValues.end() &&
        recentKeyTimestamps.find(key) != recentKeyTimestamps.end()) {
      recentKeyTimestamps[key] = timestamp;
      activeKeyTimestamps.push({key, timestamp});
      return keyValues[key];
    }

    return -1;
  }

  void put(int key, int value) {
    timestamp++;

    if (recentKeyTimestamps.find(key) != recentKeyTimestamps.end()) {
      activeKeyTimestamps.push({key, timestamp});
      recentKeyTimestamps[key] = timestamp;
      keyValues[key] = value;
      return;
    }

    if (recentKeyTimestamps.size() == keyCapacity) {
      while (activeKeyTimestamps.front().second !=
             recentKeyTimestamps[activeKeyTimestamps.front().first]) {
        activeKeyTimestamps.pop();
      }

      int key = activeKeyTimestamps.front().first;
      activeKeyTimestamps.pop();
      recentKeyTimestamps.erase(key);
      keyValues.erase(key);
    }

    keyValues[key] = value;
    recentKeyTimestamps[key] = timestamp;
    activeKeyTimestamps.push({key, timestamp});
  }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

// 460. LFU Cache
// https://leetcode.com/problems/lfu-cache/description/

using namespace std;

#include <list>
#include <unordered_map>

class LFUCache {
public:
  int capacity = 0;
  int minFrequency = 0;
  unordered_map<int, list<int>> frequencyToKeyList;
  unordered_map<int, pair<pair<int, int>, list<int>::iterator>>
      keyToFrequencyValueMap;

  LFUCache(int _capacity) { capacity = _capacity; }

  int get(int key) {
    if (keyToFrequencyValueMap.find(key) == keyToFrequencyValueMap.end()) {
      return -1;
    }

    int frequency = keyToFrequencyValueMap[key].first.first,
        value = keyToFrequencyValueMap[key].first.second;
    list<int>::iterator iter = keyToFrequencyValueMap[key].second;

    frequencyToKeyList[frequency].erase(iter);
    frequencyToKeyList[frequency + 1].push_back(key);
    iter = prev(frequencyToKeyList[frequency + 1].end());

    if (frequency == minFrequency && frequencyToKeyList[frequency].empty()) {
      minFrequency = frequency + 1;
    }

    keyToFrequencyValueMap[key].first.first = frequency + 1;
    keyToFrequencyValueMap[key].second = iter;

    return value;
  }

  void put(int key, int value) {
    if (keyToFrequencyValueMap.find(key) != keyToFrequencyValueMap.end()) {
      get(key);
      keyToFrequencyValueMap[key].first.second = value;
      return;
    }

    if (keyToFrequencyValueMap.size() == capacity) {
      int victim = frequencyToKeyList[minFrequency].front();
      keyToFrequencyValueMap.erase(victim);
      frequencyToKeyList[minFrequency].pop_front();
    }

    minFrequency = 1;
    frequencyToKeyList[minFrequency].push_back(key);
    list<int>::iterator iter = prev(frequencyToKeyList[minFrequency].end());
    keyToFrequencyValueMap[key] = {{minFrequency, value}, iter};
  }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

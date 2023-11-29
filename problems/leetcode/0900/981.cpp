// 981. Time Based Key-Value Store
// https://leetcode.com/problems/time-based-key-value-store/description/

using namespace std;

#include <string>
#include <unordered_map>
#include <vector>

class TimeMap {
public:
  unordered_map<string, vector<pair<int, string>>> store;

  TimeMap() {}

  int upperBoundForStore(string key, int timestamp) {
    if (store[key].empty()) {
      return -1;
    }

    if (timestamp >= store[key].back().first) {
      return store[key].size();
    }

    if (timestamp < store[key][0].first) {
      return -1;
    }

    int start = 0, end = store[key].size() - 1;

    while (start < end) {
      int mid = (start + end) / 2;
      if (store[key][mid].first <= timestamp) {
        start = mid + 1;
      } else {
        end = mid;
      }
    }

    return end;
  }

  void set(string key, string value, int timestamp) {
    store[key].push_back({timestamp, value});
  }

  string get(string key, int timestamp) {
    int index = upperBoundForStore(key, timestamp);

    if (index <= 0) {
      return "";
    }

    return store[key][index - 1].second;
  }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */

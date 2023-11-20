// 362. Design Hit Counter
// https://leetcode.com/problems/design-hit-counter/description/

using namespace std;

#include <map>

class HitCounter {
public:
  const int INTERVAL = 299;
  map<int, int> counts;

  HitCounter() {}

  void hit(int timestamp) {
    if (counts.empty()) {
      counts[timestamp] = 1;
    } else if (counts.find(timestamp) != counts.end()) {
      counts[timestamp]++;
    } else {
      counts[timestamp] = counts.rbegin()->second + 1;
    }
  }

  int getHits(int timestamp) {
    int target = timestamp - INTERVAL;
    map<int, int>::iterator iter = counts.lower_bound(target);

    if (iter == counts.end()) {
      return 0;
    } else if (iter == counts.begin()) {
      return counts.rbegin()->second;
    }
    return (counts.rbegin()->second - prev(iter)->second);
  }
};

/**
 * Your HitCounter object will be instantiated and called as such:
 * HitCounter* obj = new HitCounter();
 * obj->hit(timestamp);
 * int param_2 = obj->getHits(timestamp);
 */

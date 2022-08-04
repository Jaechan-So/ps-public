// 1387. Sort Integers by The Power Value
// https://github.com/Jaechan-So/ps-public/tree/main/problems/leetcode

using namespace std;

#include <map>
#include <queue>

typedef pair<int, int> pii; // (power value, given integer)

class Solution {
public:
  int getKth(int lo, int hi, int k) {
    map<int, int> powerValueSteps;

    // Integer 1 does not need any step to become 1 by power value.
    powerValueSteps.insert({1, 0});

    priority_queue<pii, vector<pii>, greater<pii>> pq;

    for (int i = lo; i <= hi; i++) {
      pq.push({getPowerValueStep(powerValueSteps, i), i});
    }

    int count = 0;
    while (count < k - 1) {
      pq.pop();
      count++;
    }

    return pq.top().second;
  }

  int getPowerValue(int n) { return (n % 2 == 0) ? (n / 2) : (3 * n + 1); }

  int getPowerValueStep(map<int, int> &powerValueSteps, int n) {
    int next = getPowerValue(n), powerValueStep = 0;

    if (powerValueSteps.find(n) == powerValueSteps.end()) {
      powerValueStep = getPowerValueStep(powerValueSteps, next) + 1;
      powerValueSteps.insert({n, powerValueStep});
    } else {
      powerValueStep = powerValueSteps[n];
    }

    return powerValueStep;
  }
};

// 1383. Maximum Performance of a Team
// https://leetcode.com/problems/maximum-performance-of-a-team/

using namespace std;

#include <queue>
#include <vector>

class Solution {
public:
  int maxPerformance(int n, vector<int> &speed, vector<int> &efficiency,
                     int k) {
    vector<pair<int, int>> engineers;
    for (int i = 0; i < n; i++) {
      engineers.push_back({efficiency[i], speed[i]});
    }

    sort(engineers.begin(), engineers.end(),
         greater<pair<int, int>>()); // descending order

    priority_queue<int, vector<int>, greater<int>> pq;
    long long currentSum = 0, maxPerformanceValue = 0;

    for (int i = 0; i < n; i++) {
      if (pq.size() > k - 1) {
        int releasedSpeed = pq.top();
        currentSum -= releasedSpeed;
        pq.pop();
      }

      pq.push(engineers[i].second);
      currentSum += engineers[i].second;

      maxPerformanceValue =
          max(maxPerformanceValue, engineers[i].first * currentSum);
    }

    return getModulo(maxPerformanceValue);
  }

  long long getModulo(long long ll) { return ll % 1000000007; }
};

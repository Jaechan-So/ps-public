// 6290. Maximize the Minimum Powered City
// https://leetcode.com/contest/biweekly-contest-95/problems/maximize-the-minimum-powered-city/
// Result: Wrong Answer (2 times)

using namespace std;

#include <numeric>
#include <queue>
#include <vector>

class Solution {
public:
  long long maxPower(vector<int> &stations, int r, int k) {
    int n = stations.size();
    vector<int> prefixSum(n + 1, 0);
    partial_sum(stations.begin(), stations.end(), prefixSum.begin() + 1);

    priority_queue<pair<int, int>, vector<pair<int, int>>,
                   greater<pair<int, int>>>
        providedPowers;
    for (int i = 0; i < n; i++) {
      int left = max(0, i - r), right = min(n - 1, i + r),
          providedPower = prefixSum[right + 1] - prefixSum[left];
      providedPowers.push({providedPower, i});
    }

    vector<bool> alreadyGrouped(n, false);
    int minPower = providedPowers.top().first,
        stationIndex = providedPowers.top().second, stationCount = 1;
    providedPowers.pop();
    for (int i = max(0, stationIndex - r); i <= min(n - 1, stationIndex + r);
         i++) {
      alreadyGrouped[i] = true;
    }

    while (!providedPowers.empty()) {
      int targetPower = providedPowers.top().first,
          targetIndex = providedPowers.top().second;
      providedPowers.pop();
      if (alreadyGrouped[targetIndex]) {
        continue;
      }

      if (k <= (targetPower - minPower) * stationCount) {
        return minPower + (k / stationCount);
      }

      k -= (targetPower - minPower) * stationCount;
      stationCount++;
      minPower = targetPower;
      for (int i = max(0, targetIndex - r); i <= min(n - 1, targetIndex + r);
           i++) {
        alreadyGrouped[i] = true;
      }
    }

    return minPower + (k / stationCount);
  }
};

// 그룹 찾기
// 주어진 stations와 r로 값을 구해서 시작
// 가장 작은 값의 r 안 그룹핑하고 그룹 안에 없는 가장 작은 값 찾아야 함

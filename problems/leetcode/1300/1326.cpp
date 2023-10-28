// 1326. Minimum Number of Taps to Open to Water a Garden
// https://leetcode.com/problems/minimum-number-of-taps-to-open-to-water-a-garden/description/

using namespace std;

#include <vector>

class Solution {
public:
  int minTaps(int n, vector<int> &ranges) {
    vector<int> prevMinTaps(n + 1, INT_MAX);
    prevMinTaps[0] = 0;
    for (int i = 0; i <= min(n, ranges[0]); i++) {
      prevMinTaps[i] = min(prevMinTaps[i], 1);
    }

    for (int i = 1; i <= n; i++) {
      if (ranges[i] == 0) {
        continue;
      }

      int coveredLeft = max(0, i - ranges[i]),
          coveredRight = min(n, i + ranges[i]);
      if (prevMinTaps[coveredLeft] != INT_MAX) {
        for (int j = coveredLeft + 1; j <= coveredRight; j++) {
          prevMinTaps[j] = min(prevMinTaps[j], 1 + prevMinTaps[coveredLeft]);
        }
      }
    }

    return prevMinTaps[n] != INT_MAX ? prevMinTaps[n] : -1;
  }
};

// 1. Naive Solution
// 각각의 Tap을 키고 끄는 모든 경우의 수에 대해서 (2^(n + 1))
// 모든 영역이 커버되는지 확인한다. (n^2)
// O((2^n) * (n^2))

// 2. Improved, DP
// dp[n] -> 최소 횟수로 0 ~ n 영역을 모두 커버하면서, 오른쪽으로 가장 많이
// 넘어간 방법. dp[n + 1] -> dp[n]이 n ~ n + 1 영역을 커버하고 있으면, dp[n]이
// 후보가 될 수 있음. ranges[n + 1]이 포함되어 값이 더 줄어들거나 오른쪽으로
// 넘어간 영역이 더 커질 수도 있음. 1 + dp[(n + 1) - ranges[n + 1]] dp[n]이 n ~
// n + 1 영역을 커버하고 있으면, 현재로써는 무조건 ranges[n + 1]을 포함시켜야
// 함. 실질적으로 ranges[i] == 0인 i는 의미가 없는 것 같다.
//
// 초기값: 0 ~ 0을 커버하기 위해서는 minTap = 0, range = 0
// 0 ~ 1을 커버하기 위해서는 dp 값을 참조하는 것이 아니라, range[0]과 range[1]
// 값을 참조해야 함. 커버하지 못하는 경우가 있을 수 있어서, minTap에 -1도
// 저장해야 할 수 있음. 그렇게 되면, dp의 새로운 항을 계산할 때, 최소를 보장할
// 수 없을 것 같음.
//
// i. dp[n]을 유지하고, n + 1번째 Tap은 켜지 않을 경우
// ii. dp[n]을 유지하고, n + 1번째 Tap도 켜는 경우
// iii. n + 1번째 Tap을 켜고, dp[(n + 1) - ranges[n + 1]]까지의 값을 이용하는
// 경우

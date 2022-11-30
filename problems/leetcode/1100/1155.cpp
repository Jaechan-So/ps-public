// 1155. Number of Dice Rolls With Target Sum
// https://leetcode.com/problems/number-of-dice-rolls-with-target-sum/

using namespace std;

#include <algorithm>

class Solution {
public:
  long long dp[31][1001];

  int numRollsToTarget(int n, int k, int target) {
    for (int i = 0; i < 31; i++) {
      for (int j = 0; j < 1001; j++) {
        dp[i][j] = -1;
      }
    }

    return (int)getModulo(findNumRolls(n, k, target));
  }

  long long getModulo(long long ll) { return ll % 1000000007; }

  long long findNumRolls(int m, int j, int s) {
    if (dp[m][s] != -1) {
      return dp[m][s];
    }

    if (m == 1) {
      return 1 <= s && s <= j ? 1 : 0;
    }

    if (m > s || s > m * j) {
      dp[m][s] = 0;
      return 0;
    }

    long long numRolls = 0;
    for (int i = s - 1; i >= max(1, s - j); i--) {
      numRolls += findNumRolls(m - 1, j, i);
    }
    dp[m][s] = getModulo(numRolls);

    return dp[m][s];
  }
};

// Notes
// dp[n][k][t] = dp[n - 1][k][t - 1~k, t' >= 1]
// dp[2][6][3] = dp[1][6][2] + dp[1][6][1]
// dp[1][k][t] = 1 <= t <= k ? 1 : 0
// dp[3][6][3] = dp[2][6][2] + dp[2][6][1]
// dp[n][k][t] where n > t => 0.
// dp[n][k][t] Available Range: n <= t <= k * n. If it is outside of range, then
// the value is 0. dp[2][6][2] = dp[1][6][1]

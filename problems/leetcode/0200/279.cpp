// 279. Perfect Squares
// https://leetcode.com/problems/perfect-squares/description/

using namespace std;

#include <algorithm>

class Solution {
public:
  int numSquares(int n) {
    int dp[10001];
    dp[0] = 0;
    dp[1] = 1;

    for (int i = 2; i <= n; i++) {
      int minSquare = INT_MAX;

      for (int k = 1; k * k <= i; k++) {
        minSquare = min(minSquare, dp[i - k * k] + 1);
      }

      dp[i] = minSquare;
    }

    return dp[n];
  }
};

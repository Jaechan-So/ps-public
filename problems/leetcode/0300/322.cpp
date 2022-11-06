// 322. Coin Change
// https://leetcode.com/problems/coin-change/

using namespace std;

#include <vector>

class Solution {
public:
  int coinChange(vector<int> &coins, int amount) {
    // dp[i][j]: until "i"-th coin("i" = 0: no coin), with amount "j", the
    // number of change
    int dp[13][10001] = {
        0,
    };
    for (int i = 0; i < 10001; i++) {
      dp[0][i] = -1;
    }

    // dp[i][j] = min(dp[i - 1][j], dp[i][j - coins[i]] + 1)
    // Since there are base cases with "i" == 0 and "j" == 0, consider them.
    // Need to handle:
    // 1. when j - coins[i] < 0
    // 2. dp[x][y] == -1 wherever
    for (int i = 0; i < coins.size(); i++) {
      for (int j = 1; j <= amount; j++) {
        int prevCoinChange = dp[i][j];
        int prevAmountChange = j - coins[i] >= 0 ? dp[i + 1][j - coins[i]] : -1;

        if (prevCoinChange == -1 && prevAmountChange == -1) {
          dp[i + 1][j] = -1;
        } else if (prevCoinChange == -1 && prevAmountChange != -1) {
          dp[i + 1][j] = prevAmountChange + 1;
        } else if (prevCoinChange != -1 && prevAmountChange == -1) {
          dp[i + 1][j] = prevCoinChange;
        } else {
          dp[i + 1][j] = min(prevCoinChange, prevAmountChange + 1);
        }
      }
    }

    return dp[coins.size()][amount];
  }
};

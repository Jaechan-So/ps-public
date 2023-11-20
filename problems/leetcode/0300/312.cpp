// 312. Burst Balloons
// https://leetcode.com/problems/burst-balloons/description/

using namespace std;

#include <vector>

class Solution {
public:
  vector<vector<int>> dp;

  int getMaxCoinsInRange(vector<int> &nums, int start, int end) {
    if (dp[start][end] != -1) {
      return dp[start][end];
    }

    int coins = INT_MIN;
    for (int k = start; k <= end; k++) {
      int leftCoins =
          start > k - 1 ? 0 : getMaxCoinsInRange(nums, start, k - 1);
      int rightCoins = k + 1 > end ? 0 : getMaxCoinsInRange(nums, k + 1, end);
      int left = start - 1 < 0 ? 1 : nums[start - 1];
      int right = end + 1 >= nums.size() ? 1 : nums[end + 1];
      int totalCoins = leftCoins + (left * nums[k] * right) + rightCoins;
      coins = max(coins, totalCoins);
    }
    dp[start][end] = coins;

    return dp[start][end];
  }

  int maxCoins(vector<int> &nums) {
    int n = nums.size();
    dp = vector<vector<int>>(n, vector<int>(n, -1));
    return getMaxCoinsInRange(nums, 0, n - 1);
  }
};

// [Solution] DP
// dp[i][j]: i ~ j 범위에서의 최대 획득량
// dp[i][j] = max_(k = i to j)(dp[i][k - 1] + nums[i - 1] * nums[k] * nums[j +
// 1] + dp[k + 1][j])

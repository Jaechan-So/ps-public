// 410. Split Array Largest Sum
// https://leetcode.com/problems/split-array-largest-sum/description/

using namespace std;

#include <vector>

class Solution {
public:
  int splitArray(vector<int> &nums, int k) {
    int n = nums.size();
    vector<int> sums(n, 0);

    vector<int> prefix(n + 1, 0);
    for (int i = 1; i <= n; i++) {
      prefix[i] = prefix[i - 1] + nums[i - 1];
      sums[i - 1] = prefix[i];
    }

    for (int j = 2; j <= k; j++) {
      vector<int> newSums(sums);

      for (int i = 0; i < n; i++) {
        int sum = INT_MAX;

        for (int k = 0; k < i; k++) {
          sum = min(sum, max(sums[k], (prefix[i + 1] - prefix[k + 1])));
        }

        newSums[i] = sum;
      }

      sums = newSums;
    }

    return sums[n - 1];
  }
};

// 1. Naive
// O((n + 1) C k * n)

// 2. DP
// dp[i][j]: i번째까지 j개의 split으로 쪼갰을 때의 min of max of sums
// dp[i][j] = min_(k = 0 to i)(max(dp[k][j - 1], sum btw k + 1 to i))

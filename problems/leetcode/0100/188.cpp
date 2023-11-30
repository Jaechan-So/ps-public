// 188. Best Time to Buy and Sell Stock IV
// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/description/

using namespace std;

#include <vector>

class Solution {
public:
  vector<vector<int>> memo;

  int getMaxProfit(vector<int> &prices, int end, int transactions) {
    if (end <= 0 || transactions == 0) {
      return 0;
    }

    if (memo[end][transactions] != -1) {
      return memo[end][transactions];
    }

    int minPrice = prices[end], maxPrice = prices[end], profit = 0;
    for (int i = end; i >= 0; i--) {
      int profitInTransaction = maxPrice - prices[i];
      if (profitInTransaction > 0) {
        profit = max(profit, profitInTransaction +
                                 getMaxProfit(prices, i - 1, transactions - 1));
      }
      maxPrice = max(maxPrice, prices[i]);
    }

    memo[end][transactions] = profit;
    return memo[end][transactions];
  }

  int maxProfit(int k, vector<int> &prices) {
    int n = prices.size();
    memo = vector<vector<int>>(n, vector<int>(k + 1, -1));
    return getMaxProfit(prices, n - 1, k);
  }
};

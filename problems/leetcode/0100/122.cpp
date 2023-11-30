// 122. Best Time to Buy and Sell Stock II
// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/description/

using namespace std;

#include <vector>

class Solution {
public:
  int maxProfit(vector<int> &prices) {
    int n = prices.size(), profit = 0;

    for (int i = 1; i < n; i++) {
      int diff = prices[i] - prices[i - 1];
      if (diff > 0) {
        profit += diff;
      }
    }

    return profit;
  }
};

// 714. Best Time to Buy and Sell Stock with Transaction Fee
// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/description/

using namespace std;

#include <utility>
#include <vector>

class Solution {
public:
  int maxProfit(vector<int> &prices, int fee) {
    int buy = 0, sell = 0, nothing = 0, diff = INT_MIN;

    for (int i = 0; i < prices.size(); i++) {
      int price = prices[i];

      int localBuy = sell;
      int localSell = i == 0 ? 0 : diff + price - fee;
      int localNothing = max({buy, sell, nothing});

      buy = max(buy, localBuy);
      sell = max(sell, localSell);
      nothing = max(nothing, localNothing);
      diff = max(diff, localBuy - price);
    }

    return max({buy, sell, nothing});
  }
};

// 그 지점의 살 때 값: 그냥 이전 꺼 중에서 팔 때 최대값 찾으면 됨.
// 그 지점의 팔 때 값: 이전 꺼 중에서 (살 때 값 - 이전 지점 값)이 최대인 곳
// 찾으면 됨. 그러면 (살 때 값 + (그 지점 값 - 이전 지점 값 - fee)) 그 지점에서
// 아무 것도 안 할 때 값: 이전 꺼 중에서 모든 종류의 최대값.

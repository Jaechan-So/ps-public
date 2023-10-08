// 123. Best Time to Buy and Sell Stock III
// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/description/

using namespace std;

#include <vector>

class Solution {
public:
  int maxProfit(vector<int> &prices) {
    int n = prices.size();
    vector<int> profitFromLeftToRight(n, 0), profitFromRightToLeft(n, 0);

    int minPrice = INT_MAX, maxLocalProfit = INT_MIN;
    for (int i = 0; i < n; i++) {
      minPrice = min(minPrice, prices[i]);
      maxLocalProfit = max(maxLocalProfit, max(prices[i] - minPrice, 0));
      profitFromLeftToRight[i] = maxLocalProfit;
    }

    int maxPrice = INT_MIN;
    maxLocalProfit = INT_MIN;
    for (int i = n - 1; i >= 0; i--) {
      maxPrice = max(maxPrice, prices[i]);
      maxLocalProfit = max(maxLocalProfit, max(maxPrice - prices[i], 0));
      profitFromRightToLeft[i] = maxLocalProfit;
    }

    int profit = 0;
    for (int i = 0; i < n; i++) {
      profit = max(profit, profitFromLeftToRight[i] + profitFromRightToLeft[i]);
    }

    return profit;
  }
};

// 연속된 prices에 하나가 추가되면, max((추가된 값) - (이전 값들 중 최소값),
// 0)이 해당 구간에서 얻을 수 있는 최대 transaction. 왼쪽에서 오른쪽으로 가는
// 방향 1개와, 오른쪽에서 왼쪽으로 가는 방향 1개로 만든다.

// 왼쪽에서 오른쪽으로 가면서, 1. 값들 간의 최솟값, 2. max(prices[i] - (1번의
// 값)), 3. 2번 값의 최대값 을 저장한다. 오른쪽에서 왼쪽으로도 마찬가지. 3번의
// 값들을 순회하면서 값을 더한다.

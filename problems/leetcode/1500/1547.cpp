// 1547. Minimum Cost to Cut a Stick
// https://leetcode.com/problems/minimum-cost-to-cut-a-stick/description/

using namespace std;

#include <vector>

class Solution {
public:
  vector<vector<int>> memo;
  vector<int> totalCuts;

  int dp(int left, int right) {
    if (memo[left][right] != -1) {
      return memo[left][right];
    }

    if (right - left == 1) {
      return 0;
    }

    int cost = INT_MAX;
    for (int c = left + 1; c <= right - 1; c++) {
      int currentCost =
          dp(left, c) + dp(c, right) + totalCuts[right] - totalCuts[left];
      cost = min(cost, currentCost);
    }

    memo[left][right] = cost;
    return cost;
  }

  int minCost(int n, vector<int> &cuts) {
    sort(cuts.begin(), cuts.end());
    int m = cuts.size();
    memo = vector<vector<int>>(m + 2, vector<int>(m + 2, -1));

    totalCuts.push_back(0);
    for (int c : cuts) {
      totalCuts.push_back(c);
    }
    totalCuts.push_back(n);

    return dp(0, m + 1);
  }
};

// 1. Naive, Backtracking
// 모든 경우를 시도해본다. O(n!)

// 막대의 [a, b] 안에서 c1, c2(a < c1 < c2 < b)로 자르면
// 자르는 순간의 비용은 (b - a)
// 다음 자르는 순간의 비용은 (c2 - a) vs. (b - c1)
// c2 - a < b - c1이 의미하는 바는, c2가 a에 가까운 정도가 c1이 b에 가까운
// 정도보다 더 크다는 뜻. c1 < c2이므로, 다시 말해서 중앙에 더 가깝다가 됨.
// 우선, 2개만 남았을 때 중앙에 더 가까운 것을 자르는 것이 유리하다는 것은
// 증명되었다.

// [a, b] 안에서 a < c1 < c2 < c3 < b 일 때 ci로 자르면 (어차피 (b - a)는 같으니
// 생략) c2로 먼저 잘랐을 때 -> (c2 - a) + (b - c2) = b - a c1으로 먼저 잘랐을
// 때 -> (b - c1) + min(c3 - c1, b - c2) c3로 먼저 잘랐을 때 -> (c3 - a) +
// min(c2 - a, c3 - c1)

// 2. DP
// min(f(a, c), f(c, b)) + (b - a)

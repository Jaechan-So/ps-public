// 818. Race Car
// https://leetcode.com/problems/race-car/description/

using namespace std;

#include <vector>

class Solution {
public:
  int racecar(int target) {
    vector<int> dp(target + 1, -1);
    return getMinimumInstructions(dp, target);
  }

  int getMinimumInstructions(vector<int> &dp, int index) {
    if (dp[index] >= 0) {
      return dp[index];
    }

    dp[index] = INT_MAX;

    int forwardPosition = 1, accCount = 1;

    for (; forwardPosition < index; forwardPosition = (1 << ++accCount) - 1) {
      for (int backwardPosition = 0, revCount = 0;
           forwardPosition - backwardPosition > 0;
           backwardPosition = (1 << ++revCount) - 1) {
        dp[index] =
            min(dp[index],
                accCount + 1 + revCount + 1 +
                    getMinimumInstructions(
                        dp, index - (forwardPosition - backwardPosition)));
      }
    }
    dp[index] =
        min(dp[index], accCount + (forwardPosition == index
                                       ? 0
                                       : 1 + getMinimumInstructions(
                                                 dp, forwardPosition - index)));

    return dp[index];
  }
};

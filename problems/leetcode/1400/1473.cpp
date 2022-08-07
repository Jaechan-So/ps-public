// 1473. Paint House III
// https://leetcode.com/problems/paint-house-iii/

using namespace std;

#include <vector>

class Solution {
public:
  // Parameters with house index, target, color.
  int dp[101][101][21] = {
      0,
  };

  int minCost(vector<int> &houses, vector<vector<int>> &cost, int m, int n,
              int target) {
    int result = dfs(houses, cost, 0, target, 0);
    return result > 1000000 ? -1 : result;
  }

  int dfs(vector<int> &houses, vector<vector<int>> &cost, int index, int target,
          int color) {
    // If target == 0, then the function call branch is valid, so return 0 for
    // adding all footprints. Otherwise, if target < 0, there are more
    // neighborhood then our expected target, so return invalid value.
    if (index >= houses.size() || target < 0) {
      return target == 0 ? 0 : 1000001;
    }

    // Use memoized value.
    if (dp[index][target][color]) {
      return dp[index][target][color];
    }

    int result = 1000001;

    // If houses[index] != 0, then we are able to just use that color.
    // Otherwise, if houses[index] == 0, we have to judge all colors whether fit
    // or not.
    if (houses[index] != 0) {
      int nextTarget = color == houses[index] ? target : target - 1;
      result = dfs(houses, cost, index + 1, nextTarget, houses[index]);
    } else {
      for (int colorCandidate = 1; colorCandidate <= cost[index].size();
           colorCandidate++) {
        int nextTarget = color == colorCandidate ? target : target - 1;
        result = min(result, cost[index][colorCandidate - 1] +
                                 dfs(houses, cost, index + 1, nextTarget,
                                     colorCandidate));
      }
    }

    dp[index][target][color] = result;
    return result;
  }
};

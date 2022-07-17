// 1000. Minimum Cost to Merge Stones
// https://leetcode.com/problems/minimum-cost-to-merge-stones/

using namespace std;

#include <vector>

class Solution {
public:
  int mergeStones(vector<int> &stones, int k) {
    int costs[30][30] = {
        0,
    };
    int partialSum[31] = {
        0,
    };

    int stoneCount = stones.size();
    if ((stoneCount - 1) % (k - 1) != 0) {
      return -1;
    }

    for (int i = 1; i <= stoneCount; i++) {
      partialSum[i] = partialSum[i - 1] + stones[i - 1];
    }

    for (int i = k; i <= stoneCount; i++) {
      for (int j = 0, l = j + i - 1; l < stoneCount; j++, l++) {
        costs[j][l] = INT_MAX;

        for (int m = j; m < l; m += (k - 1)) {
          costs[j][l] = min(costs[j][l], costs[j][m] + costs[m + 1][l]);
        }

        if ((i - 1) % (k - 1) == 0) {
          costs[j][l] += partialSum[l + 1] - partialSum[j];
        }
      }
    }

    return costs[0][stoneCount - 1];
  }
};

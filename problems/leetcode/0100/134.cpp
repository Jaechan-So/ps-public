// 134. Gas Station
// https://leetcode.com/problems/gas-station/

using namespace std;

#include <vector>

class Solution {
public:
  int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
    int n = gas.size();
    vector<int> profitAndLoss(n, 0);

    for (int i = 0; i < n; i++) {
      profitAndLoss[i] = gas[i] - cost[i];
    }

    int best = -1, sum = 0;
    for (int i = 0; i < n; i++) {
      if (best < 0 && profitAndLoss[i] >= 0) {
        best = i;
        sum = profitAndLoss[i];
        continue;
      }
      if (best >= 0) {
        sum += profitAndLoss[i];
        if (sum < 0) {
          best = -1;
        }
      }
    }

    if (best >= 0) {
      int i = best, final_sum = 0;
      for (int count = n; count != 0; count--) {
        final_sum += profitAndLoss[i];
        if (final_sum < 0) {
          return -1;
        }
        i = (i + 1) % n;
      }
    }

    return best;
  }
};

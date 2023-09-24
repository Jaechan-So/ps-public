// 2866. Beautiful Towers II
// https://leetcode.com/contest/weekly-contest-364/problems/beautiful-towers-ii/
// Result: Failed to Reach

using namespace std;

#include <vector>

class Solution {
public:
  long long maximumSumOfHeights(vector<int> &maxHeights) {
    int n = maxHeights.size();

    vector<int> prevSmall(n, -1), monoInc;
    for (int i = 0; i < n; i++) {
      while (!monoInc.empty() && maxHeights[monoInc.back()] >= maxHeights[i]) {
        monoInc.pop_back();
      }
      if (!monoInc.empty()) {
        prevSmall[i] = monoInc.back();
      }
      monoInc.push_back(i);
    }

    vector<int> nextSmall(n, n), monoDec;
    for (int i = n - 1; i >= 0; i--) {
      while (!monoDec.empty() && maxHeights[monoDec.back()] >= maxHeights[i]) {
        monoDec.pop_back();
      }
      if (!monoDec.empty()) {
        nextSmall[i] = monoDec.back();
      }
      monoDec.push_back(i);
    }

    vector<long long> leftSum(n, 0);
    for (int i = 0; i < n; i++) {
      int index = prevSmall[i];
      leftSum[i] = (maxHeights[i] * (long long)(i - index)) +
                   (index != -1 ? leftSum[index] : 0);
    }

    vector<long long> rightSum(n, 0);
    for (int i = n - 1; i >= 0; i--) {
      int index = nextSmall[i];
      rightSum[i] = (maxHeights[i] * (long long)(index - i)) +
                    (index != n ? rightSum[index] : 0);
    }

    long long maxSum = 0;
    for (int i = 0; i < n; i++) {
      maxSum = max(maxSum, leftSum[i] + rightSum[i] - maxHeights[i]);
    }

    return maxSum;
  }
};

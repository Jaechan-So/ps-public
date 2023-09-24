// 2865. Beautiful Towers I
// https://leetcode.com/contest/weekly-contest-364/problems/beautiful-towers-i/
// Result: Accepted

using namespace std;

#include <vector>

class Solution {
public:
  long long maximumSumOfHeights(vector<int> &maxHeights) {
    int n = maxHeights.size();
    long long maxSum = 0;

    for (int i = 0; i < n; i++) {
      long long sum = maxHeights[i];

      int prevHeight = maxHeights[i];
      for (int j = i - 1; j >= 0; j--) {
        // Decrease
        prevHeight = min(prevHeight, maxHeights[j]);
        sum += prevHeight;
      }

      prevHeight = maxHeights[i];
      for (int j = i + 1; j < n; j++) {
        // Increase
        prevHeight = min(prevHeight, maxHeights[j]);
        sum += prevHeight;
      }

      maxSum = max(maxSum, sum);
    }

    return maxSum;
  }
};

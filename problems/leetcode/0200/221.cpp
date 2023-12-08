// 221. Maximal Square
// https://leetcode.com/problems/maximal-square/description/

using namespace std;

#include <vector>

class Solution {
public:
  int maximalSquare(vector<vector<char>> &matrix) {
    int m = matrix.size(), n = matrix[0].size(), maxArea = 0;
    vector<int> memo(n, 0);

    for (int i = 0; i < m; i++) {
      vector<int> newMemo(n, 0);

      for (int j = 0; j < n; j++) {
        if (matrix[i][j] == '1') {
          int side = INT_MAX;

          if (j - 1 >= 0) {
            side = min(side, newMemo[j - 1]);
            side = min(side, memo[j - 1]);
          } else {
            side = 0;
          }
          side = min(side, memo[j]);

          newMemo[j] = side + 1;
          maxArea = max(maxArea, newMemo[j] * newMemo[j]);
        }
      }

      memo = newMemo;
    }

    return maxArea;
  }
};

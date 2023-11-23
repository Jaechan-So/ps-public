// 73. Set Matrix Zeroes
// https://leetcode.com/problems/set-matrix-zeroes/description/

using namespace std;

#include <vector>

class Solution {
public:
  void setZeroes(vector<vector<int>> &matrix) {
    int m = matrix.size(), n = matrix[0].size();

    bool isFirstRowNeedMask = false, isFirstColumnNeedMask = false;
    for (int i = 0; i < m; i++) {
      isFirstColumnNeedMask |= (matrix[i][0] == 0);
    }
    for (int j = 0; j < n; j++) {
      isFirstRowNeedMask |= (matrix[0][j] == 0);
    }

    for (int i = 1; i < m; i++) {
      for (int j = 1; j < n; j++) {
        if (matrix[i][j] == 0) {
          matrix[i][0] = 0;
          matrix[0][j] = 0;
        }
      }
    }

    for (int i = 1; i < m; i++) {
      for (int j = 1; j < n; j++) {
        if (matrix[i][0] == 0 || matrix[0][j] == 0) {
          matrix[i][j] = 0;
        }
      }
    }

    if (isFirstRowNeedMask) {
      for (int j = 0; j < n; j++) {
        matrix[0][j] = 0;
      }
    }
    if (isFirstColumnNeedMask) {
      for (int i = 0; i < m; i++) {
        matrix[i][0] = 0;
      }
    }
  }
};

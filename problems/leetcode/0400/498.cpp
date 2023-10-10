// 498. Diagonal Traverse
// https://leetcode.com/problems/diagonal-traverse/description/

using namespace std;

#include <vector>

class Solution {
public:
  vector<int> findDiagonalOrder(vector<vector<int>> &mat) {
    int m = mat.size(), n = mat[0].size();
    vector<int> nums;

    for (int i = 0; i <= m + n - 2; i++) {
      if (i % 2 == 0) {
        for (int j = (i > m - 1) ? (i - m + 1) : 0; j <= min(n - 1, i); j++) {
          nums.push_back(mat[i - j][j]);
        }
      } else {
        for (int j = (i > n - 1) ? (i - n + 1) : 0; j <= min(m - 1, i); j++) {
          nums.push_back(mat[j][i - j]);
        }
      }
    }

    return nums;
  }
};

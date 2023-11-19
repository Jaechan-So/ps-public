// 48. Rotate Image
// https://leetcode.com/problems/rotate-image/description/

using namespace std;

#include <vector>

class Solution {
public:
  void rotate(vector<vector<int>> &matrix) {
    int n = matrix.size();
    int originR[4] = {0, 0, n - 1, n - 1}, originC[4] = {0, n - 1, n - 1, 0};

    for (int i = 0; i < (n / 2); i++) {
      for (int j = 0; j < ((n + 1) / 2); j++) {
        int offsetR[4] = {i, j, -i, -j}, offsetC[4] = {j, -i, -j, i};
        for (int k = 3; k > 0; k--) {
          swap(matrix[originR[k] + offsetR[k]][originC[k] + offsetC[k]],
               matrix[originR[k - 1] + offsetR[k - 1]]
                     [originC[k - 1] + offsetC[k - 1]]);
        }
      }
    }
  }
};

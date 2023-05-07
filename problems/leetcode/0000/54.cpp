// 54. Spiral Matrix
// https://leetcode.com/problems/spiral-matrix/description/

#include <vector>

using namespace std;

class Solution {
public:
  vector<int> spiralOrder(vector<vector<int>> &matrix) {
    int m = matrix.size() - 1, n = matrix[0].size();
    vector<int> orderedValues;

    int x = 0, y = -1;
    do {
      if (n <= 0) {
        break;
      }
      for (int i = 1; i <= n; i++) {
        y++;
        orderedValues.push_back(matrix[x][y]);
      }
      n--;

      if (m <= 0) {
        break;
      }
      for (int i = 1; i <= m; i++) {
        x++;
        orderedValues.push_back(matrix[x][y]);
      }
      m--;

      if (n <= 0) {
        break;
      }
      for (int i = 1; i <= n; i++) {
        y--;
        orderedValues.push_back(matrix[x][y]);
      }
      n--;

      if (m <= 0) {
        break;
      }
      for (int i = 1; i <= m; i++) {
        x--;
        orderedValues.push_back(matrix[x][y]);
      }
      m--;
    } while (m > 0 || n > 0);

    return orderedValues;
  }
};

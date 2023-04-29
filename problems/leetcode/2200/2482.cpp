// 2482. Difference Between Ones and Zeros in Row and Column
// https://leetcode.com/problems/difference-between-ones-and-zeros-in-row-and-column/description/

#include <vector>

using namespace std;

class Solution {
public:
  vector<vector<int>> onesMinusZeros(vector<vector<int>> &grid) {
    int m = grid.size(), n = grid[0].size();
    vector<int> oneCountsRow(m, 0), oneCountsColumn(n, 0);

    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (grid[i][j] == 1) {
          oneCountsRow[i]++;
          oneCountsColumn[j]++;
        }
      }
    }

    vector<vector<int>> diff(m, vector<int>(n, 0));
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        diff[i][j] = 2 * (oneCountsRow[i] + oneCountsColumn[j]) - (m + n);
      }
    }

    return diff;
  }
};

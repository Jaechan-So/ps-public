// 64. Minimum Path Sum
// https://leetcode.com/problems/minimum-path-sum/submissions/

using namespace std;

#include <vector>

class Solution {
public:
  bool isValidCoordinate(int m, int n, int x, int y) {
    return x >= 0 && x < m && y >= 0 && y < n;
  }

  void traverse(vector<vector<int>> &grid, vector<vector<int>> &sums, int m,
                int n, int x, int y) {
    if (isValidCoordinate(m, n, x + 1, y) &&
        (sums[x + 1][y] < 0 || sums[x][y] + grid[x + 1][y] < sums[x + 1][y])) {
      sums[x + 1][y] = sums[x][y] + grid[x + 1][y];
      traverse(grid, sums, m, n, x + 1, y);
    }

    if (isValidCoordinate(m, n, x, y + 1) &&
        (sums[x][y + 1] < 0 || sums[x][y] + grid[x][y + 1] < sums[x][y + 1])) {
      sums[x][y + 1] = sums[x][y] + grid[x][y + 1];
      traverse(grid, sums, m, n, x, y + 1);
    }
  }

  int minPathSum(vector<vector<int>> &grid) {
    int m = grid.size(), n = grid[0].size();

    vector<vector<int>> sums(m, vector<int>(n, -1));
    sums[0][0] = grid[0][0];
    traverse(grid, sums, m, n, 0, 0);

    return sums[m - 1][n - 1];
  }
};

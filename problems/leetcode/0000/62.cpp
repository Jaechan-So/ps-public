// 62. Unique Paths
// https://leetcode.com/problems/unique-paths/

using namespace std;

#include <vector>

class Solution {
public:
  void dfs(vector<vector<int>> &grid, int x, int y) {
    if (grid[x][y] != -1) {
      return;
    }
    dfs(grid, x - 1, y);
    dfs(grid, x, y - 1);
    grid[x][y] = grid[x - 1][y] + grid[x][y - 1];
  }
  int uniquePaths(int m, int n) {
    vector<vector<int>> grid(m + 1, vector<int>(n + 1, -1));
    for (int i = 0; i < m + 1; i++) {
      grid[i][0] = 0;
    }
    for (int j = 0; j < n + 1; j++) {
      grid[0][j] = 0;
    }
    grid[1][1] = 1;
    dfs(grid, m, n);

    return grid[m][n];
  }
};

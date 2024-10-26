// 200. Number of Islands
// https://leetcode.com/problems/number-of-islands/

using namespace std;

#include <vector>

class Solution {
public:
  int m, n;
  vector<vector<bool>> visited;
  void dfs(vector<vector<char>> &grid, int i, int j) {
    visited[i][j] = true;
    if (i + 1 < m && grid[i + 1][j] == '1' && !visited[i + 1][j]) {
      dfs(grid, i + 1, j);
    }
    if (i - 1 >= 0 && grid[i - 1][j] == '1' && !visited[i - 1][j]) {
      dfs(grid, i - 1, j);
    }
    if (j + 1 < n && grid[i][j + 1] == '1' && !visited[i][j + 1]) {
      dfs(grid, i, j + 1);
    }
    if (j - 1 >= 0 && grid[i][j - 1] == '1' && !visited[i][j - 1]) {
      dfs(grid, i, j - 1);
    }
  }

  int numIslands(vector<vector<char>> &grid) {
    m = grid.size();
    n = grid[0].size();
    int answer = 0;
    vector<vector<bool>> _visited(m, vector<bool>(n, false));
    visited = _visited;

    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (grid[i][j] == '1' && !visited[i][j]) {
          dfs(grid, i, j);
          answer++;
        }
      }
    }

    return answer;
  }
};

// 695. Max Area of Island
// https://leetcode.com/problems/max-area-of-island/

#include <vector>

using namespace std;

class Solution {
 private:
  int rowCount;
  int columnCount;
  int dfs(vector<vector<int>>& grid, int x, int y) {
    if (x < 0 || x >= rowCount || y < 0 || y >= columnCount) {
      return 0;
    }
    if (grid[x][y] == 0) {
      return 0;
    }
    grid[x][y] = 0;
    return 1 + dfs(grid, x - 1, y) + dfs(grid, x + 1, y) + dfs(grid, x, y - 1) +
           dfs(grid, x, y + 1);
  }

 public:
  int maxAreaOfIsland(vector<vector<int>>& grid) {
    rowCount = grid.size();
    columnCount = grid[0].size();
    int maxArea = 0;

    for (int i = 0; i < rowCount; i++) {
      for (int j = 0; j < columnCount; j++) {
        maxArea = max(maxArea, dfs(grid, i, j));
      }
    }

    return maxArea;
  }
};

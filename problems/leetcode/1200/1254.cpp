// 1254. Number of Closed Islands
// https://leetcode.com/problems/number-of-closed-islands/description/

using namespace std;

#include <vector>

class Solution {
public:
  const int VISITED = 2;

  const int dx[4] = {1, -1, 0, 0};
  const int dy[4] = {0, 0, 1, -1};

  int isValidCoordinate(vector<vector<int>> &grid, int x, int y) {
    int m = grid.size(), n = grid[0].size();
    return x >= 0 && x < m && y >= 0 && y < n;
  }

  bool traverseLand(vector<vector<int>> &grid, int x, int y) {
    grid[x][y] = VISITED;

    bool isIsland = true;
    for (int i = 0; i < 4; i++) {
      int newX = x + dx[i], newY = y + dy[i];
      if (!isValidCoordinate(grid, newX, newY)) {
        isIsland = false;
        continue;
      }
      if (grid[newX][newY] == 0 && !traverseLand(grid, newX, newY)) {
        isIsland = false;
      }
    }

    return isIsland;
  }

  int closedIsland(vector<vector<int>> &grid) {
    int m = grid.size(), n = grid[0].size(), islandCount = 0;

    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (grid[i][j] == 0 && traverseLand(grid, i, j)) {
          islandCount++;
        }
      }
    }

    return islandCount;
  }
};

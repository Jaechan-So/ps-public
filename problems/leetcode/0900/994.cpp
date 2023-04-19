// 994. Rotting Oranges
// https://leetcode.com/problems/rotting-oranges/description/

#include <vector>

using namespace std;

enum CellState {
  EMPTY,
  FRESH,
  ROTTEN,
};

class Solution {
private:
  const int dirX[4] = {1, -1, 0, 0};
  const int dirY[4] = {0, 0, 1, -1};

public:
  void dfs(vector<vector<int>> &times, int x, int y, int minute) {
    for (int i = 0; i < 4; i++) {
      int nextX = x + dirX[i], nextY = y + dirY[i];
      if (isValidCell(times, nextX, nextY) && times[nextX][nextY] != -2 &&
          times[nextX][nextY] != 0 &&
          (times[nextX][nextY] == -1 || minute + 1 < times[nextX][nextY])) {
        times[nextX][nextY] = minute + 1;
        dfs(times, nextX, nextY, minute + 1);
      }
    }
  }

  int orangesRotting(vector<vector<int>> &grid) {
    vector<vector<int>> times(grid.size(), vector<int>(grid[0].size(), -1));
    for (int i = 0; i < grid.size(); i++) {
      for (int j = 0; j < grid[0].size(); j++) {
        times[i][j] = grid[i][j] - 2;
      }
    }

    for (int i = 0; i < grid.size(); i++) {
      for (int j = 0; j < grid[0].size(); j++) {
        if (grid[i][j] == ROTTEN) {
          dfs(times, i, j, 0);
        }
      }
    }

    int maxTime = 0;
    for (int i = 0; i < times.size(); i++) {
      for (int j = 0; j < times[0].size(); j++) {
        if (times[i][j] == -1) {
          return -1;
        }
        maxTime = max(maxTime, times[i][j]);
      }
    }

    return maxTime;
  }

  bool isValidCell(vector<vector<int>> &sizeWindow, int x, int y) {
    return x >= 0 && x < sizeWindow.size() && y >= 0 &&
           y < sizeWindow[0].size();
  }
};

// 접근 1: dfs
// 접근 2: 각 상태 별로 좌표 set, 매번 계속 set 업데이트
// 접근 3: 각 fresh orange에서 가장 가까운 rotten orange까지의 거리의 maximum

// 0 -> -2, 1 -> -1, 2 -> 0

// 1730. Shortest Path to Get Food
// https://leetcode.com/problems/shortest-path-to-get-food/

using namespace std;

#include <queue>
#include <vector>

class Solution {
public:
  int getFood(vector<vector<char>> &grid) {
    int shortestPath[200][200] = {
        0,
    };
    int m = grid.size(), n = grid[0].size(), initX, initY;

    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        shortestPath[i][j] = INT_MAX;
      }
    }

    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (isStartPosition(grid[i][j])) {
          initX = i;
          initY = j;
          break;
        }
      }
    }

    queue<pair<int, pair<int, int>>> q; // (distance, (x, y))
    shortestPath[initX][initY] = 0;
    q.push({0, {initX, initY}});

    while (!q.empty()) {
      pair<int, pair<int, int>> p = q.front();
      q.pop();
      int distance = p.first, x = p.second.first, y = p.second.second;

      if (isFoodCell(grid[x][y])) {
        return distance;
      }

      if (isActiveCell(grid, x + 1, y, m, n) &&
          shortestPath[x + 1][y] > distance + 1) {
        shortestPath[x + 1][y] = distance + 1;
        q.push({distance + 1, {x + 1, y}});
      }
      if (isActiveCell(grid, x - 1, y, m, n) &&
          shortestPath[x - 1][y] > distance + 1) {
        shortestPath[x - 1][y] = distance + 1;
        q.push({distance + 1, {x - 1, y}});
      }
      if (isActiveCell(grid, x, y - 1, m, n) &&
          shortestPath[x][y - 1] > distance + 1) {
        shortestPath[x][y - 1] = distance + 1;
        q.push({distance + 1, {x, y - 1}});
      }
      if (isActiveCell(grid, x, y + 1, m, n) &&
          shortestPath[x][y + 1] > distance + 1) {
        shortestPath[x][y + 1] = distance + 1;
        q.push({distance + 1, {x, y + 1}});
      }
    }

    return -1;
  }

  bool isStartPosition(char c) { return c == '*'; }

  bool isFoodCell(char c) { return c == '#'; }

  bool isFreeSpace(char c) { return c == 'O'; }

  bool isObstacle(char c) { return c == 'X'; }

  bool isActiveCell(vector<vector<char>> &grid, int x, int y, int m, int n) {
    return x >= 0 && x < m && y >= 0 && y < n && !isObstacle(grid[x][y]);
  }
};

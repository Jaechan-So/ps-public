// 63. Unique Paths II
// https://leetcode.com/problems/unique-paths-ii/

using namespace std;

#include <queue>
#include <utility>
#include <vector>

typedef pair<int, int> pii;

vector<pii> directions({{1, 0}, {0, 1}});

class Solution {
public:
  int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid) {
    int m = obstacleGrid.size(), n = obstacleGrid[0].size();

    pair<bool, int> paths[100][100]; // isVisited, uniquePathCount
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        paths[i][j] = {false, 0};
      }
    }

    paths[0][0] = {true, obstacleGrid[0][0] == 0};

    queue<pii> coordinates;
    coordinates.push({0, 0});

    while (!coordinates.empty()) {
      pii coordinate = coordinates.front();
      int x = coordinate.first, y = coordinate.second;
      coordinates.pop();

      for (auto &direction : directions) {
        int nextX = x + direction.first, nextY = y + direction.second;

        if (isValidPosition(nextX, nextY, m, n) &&
            isReachablePosition(obstacleGrid, nextX, nextY)) {
          bool visited = paths[nextX][nextY].first;
          if (!visited) {
            paths[nextX][nextY].first = true;
            coordinates.push({nextX, nextY});
          }
          paths[nextX][nextY].second += paths[x][y].second;
        }
      }
    }

    return paths[m - 1][n - 1].second;
  }

  bool isValidPosition(int x, int y, int m, int n) {
    return x >= 0 && x < m && y >= 0 && y < n;
  }

  bool isReachablePosition(vector<vector<int>> &obstacleGrid, int x, int y) {
    return obstacleGrid[x][y] == 0;
  }
};

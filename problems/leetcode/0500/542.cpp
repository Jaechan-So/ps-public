// 542. 01 Matrix
// https://leetcode.com/problems/01-matrix/description/

using namespace std;

#include <queue>
#include <vector>

class Solution {
public:
  const int dr[4] = {1, -1, 0, 0};
  const int dc[4] = {0, 0, 1, -1};

  vector<vector<int>> distances;

  bool isValidCoordinate(int m, int n, int r, int c) {
    return 0 <= r && r < m && 0 <= c && c < n;
  }

  vector<vector<int>> updateMatrix(vector<vector<int>> &mat) {
    int m = mat.size(), n = mat[0].size();
    distances = vector<vector<int>>(m, vector<int>(n, INT_MAX));

    queue<vector<int>> q;
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (mat[i][j] == 0) {
          q.push({0, i, j});
          distances[i][j] = 0;
        }
      }
    }

    while (!q.empty()) {
      int dist = q.front()[0], r = q.front()[1], c = q.front()[2];
      q.pop();

      for (int i = 0; i < 4; i++) {
        int newR = r + dr[i], newC = c + dc[i];
        if (isValidCoordinate(m, n, newR, newC) && mat[newR][newC] == 1 &&
            dist + 1 < distances[newR][newC]) {
          distances[newR][newC] = dist + 1;
          q.push({distances[newR][newC], newR, newC});
        }
      }
    }

    return distances;
  }
};

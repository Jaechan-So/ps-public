// 417. Pacific Atlantic Water Flow
// https://leetcode.com/problems/pacific-atlantic-water-flow/description/

using namespace std;

#include <queue>
#include <vector>

class Solution {
public:
  const int dx[4] = {1, -1, 0, 0};
  const int dy[4] = {0, 0, 1, -1};

  vector<vector<int>> pacificAtlantic(vector<vector<int>> &heights) {
    int m = heights.size(), n = heights[0].size();
    vector<vector<bool>> flowPacific(m, vector<bool>(n, false)),
        flowAtlantic(m, vector<bool>(n, false));

    queue<vector<int>> q1;
    for (int i = 0; i < m; i++) {
      q1.push({i, n - 1});
      flowAtlantic[i][n - 1] = true;
    }
    for (int i = 0; i < n - 1; i++) {
      q1.push({m - 1, i});
      flowAtlantic[m - 1][i] = true;
    }

    while (!q1.empty()) {
      int x = q1.front()[0], y = q1.front()[1];
      q1.pop();

      for (int i = 0; i < 4; i++) {
        int newX = x + dx[i], newY = y + dy[i];
        if (0 <= newX && newX < m && 0 <= newY && newY < n &&
            heights[newX][newY] >= heights[x][y] && !flowAtlantic[newX][newY]) {
          flowAtlantic[newX][newY] = true;
          q1.push({newX, newY});
        }
      }
    }

    queue<vector<int>> q2;
    for (int i = 0; i < m; i++) {
      q2.push({i, 0});
      flowPacific[i][0] = true;
    }
    for (int i = 1; i < n; i++) {
      q2.push({0, i});
      flowPacific[0][i] = true;
    }

    while (!q2.empty()) {
      int x = q2.front()[0], y = q2.front()[1];
      q2.pop();

      for (int i = 0; i < 4; i++) {
        int newX = x + dx[i], newY = y + dy[i];
        if (0 <= newX && newX < m && 0 <= newY && newY < n &&
            heights[newX][newY] >= heights[x][y] && !flowPacific[newX][newY]) {
          flowPacific[newX][newY] = true;
          q2.push({newX, newY});
        }
      }
    }

    vector<vector<int>> results;
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (flowAtlantic[i][j] && flowPacific[i][j]) {
          results.push_back({i, j});
        }
      }
    }

    return results;
  }
};

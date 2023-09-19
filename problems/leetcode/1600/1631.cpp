// 1631. Path With Minimum Effort
// https://leetcode.com/problems/path-with-minimum-effort/description/

using namespace std;

#include <queue>
#include <vector>

class Solution {
public:
  const int dx[4] = {1, -1, 0, 0};
  const int dy[4] = {0, 0, 1, -1};

  int minimumEffortPath(vector<vector<int>> &heights) {
    int m = heights.size(), n = heights[0].size();
    vector<vector<int>> efforts(m, vector<int>(n, INT_MAX));

    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
    pq.push({0, 0, 0}); // (effort, x, y)
    efforts[0][0] = 0;

    while (!pq.empty()) {
      int effort = pq.top()[0], x = pq.top()[1], y = pq.top()[2];
      pq.pop();

      for (int i = 0; i < 4; i++) {
        int newX = x + dx[i], newY = y + dy[i];
        if (0 <= newX && newX < m && 0 <= newY && newY < n &&
            max(effort, abs(heights[x][y] - heights[newX][newY])) <
                efforts[newX][newY]) {
          efforts[newX][newY] =
              max(effort, abs(heights[x][y] - heights[newX][newY]));
          pq.push({efforts[newX][newY], newX, newY});
        }
      }
    }

    return efforts[m - 1][n - 1];
  }
};

// 329. Longest Increasing Path in a Matrix
// https://leetcode.com/problems/longest-increasing-path-in-a-matrix/description/

using namespace std;

#include <vector>

class Solution {
public:
  const int dr[4] = {0, 0, 1, -1};
  const int dc[4] = {1, -1, 0, 0};

  int m = 0, n = 0;
  vector<vector<int>> memo;

  bool isValidCoordinate(int r, int c) {
    return 0 <= r && r < m && 0 <= c && c < n;
  }

  int dfs(vector<vector<int>> &matrix, int r, int c) {
    if (memo[r][c] != -1) {
      return memo[r][c];
    }

    memo[r][c] = 1;
    for (int i = 0; i < 4; i++) {
      int newR = r + dr[i], newC = c + dc[i];
      if (isValidCoordinate(newR, newC) && matrix[r][c] < matrix[newR][newC]) {
        memo[r][c] = max(memo[r][c], 1 + dfs(matrix, newR, newC));
      }
    }

    return memo[r][c];
  }

  int longestIncreasingPath(vector<vector<int>> &matrix) {
    m = matrix.size(), n = matrix[0].size();
    memo = vector<vector<int>>(m, vector<int>(n, -1));

    int length = 0;
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        length = max(length, dfs(matrix, i, j));
      }
    }

    return length;
  }
};

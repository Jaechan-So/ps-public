// 741. Cherry Pickup
// https://leetcode.com/problems/cherry-pickup/description/

using namespace std;

#include <vector>

class Solution {
public:
  int n;
  vector<vector<vector<int>>> dp;

  bool isValidCoordinate(int r, int c) {
    return 0 <= r && r < n && 0 <= c && c < n;
  }

  int dfs(vector<vector<int>> &grid, int r1, int c1, int r2) {
    int c2 = (r1 + c1) - r2;
    if (!isValidCoordinate(r1, c1) || !isValidCoordinate(r2, c2) ||
        grid[r1][c1] == -1 || grid[r2][c2] == -1) {
      return -2;
    }

    if (r1 == n - 1 && c1 == n - 1) {
      return grid[r1][c1];
    }

    if (dp[r1][c1][r2] != -1) {
      return dp[r1][c1][r2];
    }

    int newCherries = grid[r1][c1] + grid[r2][c2];
    if (r1 == r2 && c1 == c2 && newCherries == 2) {
      newCherries = 1;
    }

    int nextResults[4] = {
        dfs(grid, r1 + 1, c1, r2),
        dfs(grid, r1, c1 + 1, r2),
        dfs(grid, r1 + 1, c1, r2 + 1),
        dfs(grid, r1, c1 + 1, r2 + 1),
    };

    int result = *max_element(nextResults, nextResults + 4);
    if (result == -2) {
      dp[r1][c1][r2] = -2;
      return -2;
    }

    dp[r1][c1][r2] = result + newCherries;
    return dp[r1][c1][r2];
  }

  int cherryPickup(vector<vector<int>> &grid) {
    n = grid.size();
    dp = vector<vector<vector<int>>>(
        n, vector<vector<int>>(n, vector<int>(n, -1)));
    dp[n - 1][n - 1][n - 1] = grid[n - 1][n - 1];

    dfs(grid, 0, 0, 0);
    return dp[0][0][0] == -2 ? 0 : dp[0][0][0];
  }
};

// 2번 계산의 반례? -> 애초에 체리 개수가 동일한 경로들에 대한 경우를 확인할
// 방법이 없음.

// 289. Game of Life
// https://leetcode.com/problems/game-of-life/

using namespace std;

#include <vector>

class Solution {
public:
  int m, n;
  bool isValidPosition(int x, int y) {
    return x >= 0 && x < m && y >= 0 && y < n;
  }
  void gameOfLife(vector<vector<int>> &board) {
    m = board.size(), n = board[0].size();
    vector<vector<int>> v(m, vector<int>(n, 0));
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        int xs[8] = {i - 1, i, i + 1, i - 1, i + 1, i - 1, i, i + 1};
        int ys[8] = {j + 1, j + 1, j + 1, j, j, j - 1, j - 1, j - 1};

        for (int k = 0; k < 8; k++) {
          if (board[i][j] && isValidPosition(xs[k], ys[k])) {
            v[xs[k]][ys[k]]++;
          }
        }
      }
    }

    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (board[i][j]) {
          if (v[i][j] < 2 || v[i][j] > 3) {
            board[i][j] = 0;
          } else {
            board[i][j] = 1;
          }
        } else {
          if (v[i][j] == 3) {
            board[i][j] = 1;
          } else {
            board[i][j] = 0;
          }
        }
      }
    }
  }
};

// 130. Surrounded Regions
// https://leetcode.com/problems/surrounded-regions/description/

using namespace std;

#include <vector>

class Solution {
public:
  const int dx[4] = {1, -1, 0, 0};
  const int dy[4] = {0, 0, 1, -1};

  int m = 0, n = 0;
  vector<vector<bool>> visited;

  bool isValidIndex(int i, int j) { return 0 <= i && i < m && 0 <= j && j < n; }

  bool isFlippable(vector<vector<char>> &board, int i, int j) {
    bool flippable = true;

    visited[i][j] = true;

    for (int k = 0; k < 4; k++) {
      int newX = i + dx[k], newY = j + dy[k];

      if (!isValidIndex(newX, newY)) {
        flippable = false;
        continue;
      }

      if (visited[newX][newY] || board[newX][newY] == 'X') {
        continue;
      }

      bool result = isFlippable(board, newX, newY);
      if (result == false) {
        flippable = false;
      }
    }

    return flippable;
  }

  void flip(vector<vector<char>> &board, int i, int j) {
    board[i][j] = 'X';

    for (int k = 0; k < 4; k++) {
      int newX = i + dx[k], newY = j + dy[k];

      if (isValidIndex(newX, newY) && board[newX][newY] == 'O') {
        flip(board, newX, newY);
      }
    }
  }

  void solve(vector<vector<char>> &board) {
    m = board.size(), n = board[0].size();
    visited = vector<vector<bool>>(m, vector<bool>(n, false));

    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (board[i][j] == 'O' && !visited[i][j] && isFlippable(board, i, j)) {
          flip(board, i, j);
        }
      }
    }
  }
};

// O O O O X X
// O O O O O O
// O X O X O O
// O X O O X O
// O X O X O O
// O X O O O O

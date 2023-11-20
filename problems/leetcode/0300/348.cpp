// 348. Design Tic-Tac-Toe
// https://leetcode.com/problems/design-tic-tac-toe/description/

using namespace std;

#include <vector>

class TicTacToe {
public:
  vector<vector<int>> rows, cols, diags;
  int side;

  TicTacToe(int n) {
    rows = vector<vector<int>>(3, vector<int>(n, 0));
    cols = vector<vector<int>>(3, vector<int>(n, 0));
    diags = vector<vector<int>>(
        3, vector<int>(2, 0)); // (row == col, row + col == side - 1)
    side = n;
  }

  int move(int row, int col, int player) {
    rows[player][row]++;
    cols[player][col]++;

    if (row == col) {
      diags[player][0]++;
    }
    if (row + col == (side - 1)) {
      diags[player][1]++;
    }

    if (rows[player][row] == side || cols[player][col] == side ||
        diags[player][0] == side || diags[player][1] == side) {
      return player;
    }
    return 0;
  }
};

/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe* obj = new TicTacToe(n);
 * int param_1 = obj->move(row,col,player);
 */

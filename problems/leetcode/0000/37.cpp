// 37. Sudoku Solver
// https://leetcode.com/problems/sudoku-solver/description/

using namespace std;

#include <unordered_set>
#include <vector>

class Solution {
public:
  vector<unordered_set<char>> row, column, bucket;

  int rowColToBucket(int r, int c) { return 3 * (r / 3) + (c / 3); }

  void init() {
    row = vector<unordered_set<char>>(9);
    column = vector<unordered_set<char>>(9);
    bucket = vector<unordered_set<char>>(9);

    for (int i = 0; i < 9; i++) {
      for (char j = '1'; j <= '9'; j++) {
        row[i].insert(j);
        column[i].insert(j);
        bucket[i].insert(j);
      }
    }
  }

  bool fill(vector<vector<char>> &board, int index) {
    if (index == 81) {
      return true;
    }

    int r = index / 9, c = index % 9, b = rowColToBucket(r, c);
    if (board[r][c] != '.') {
      return fill(board, index + 1);
    }

    for (char i = '1'; i <= '9'; i++) {
      if (row[r].find(i) != row[r].end() &&
          column[c].find(i) != column[c].end() &&
          bucket[b].find(i) != bucket[b].end()) {
        board[r][c] = i;
        row[r].erase(i);
        column[c].erase(i);
        bucket[b].erase(i);

        bool result = fill(board, index + 1);
        if (result) {
          return true;
        }

        row[r].insert(i);
        column[c].insert(i);
        bucket[b].insert(i);
        board[r][c] = '.';
      }
    }

    return false;
  }

  void solveSudoku(vector<vector<char>> &board) {
    init();

    for (int i = 0; i < 9; i++) {
      for (int j = 0; j < 9; j++) {
        int b = rowColToBucket(i, j);
        char ch = board[i][j];

        if (ch != '.') {
          row[i].erase(ch);
          column[j].erase(ch);
          bucket[b].erase(ch);
        }
      }
    }

    fill(board, 0);
  }
};

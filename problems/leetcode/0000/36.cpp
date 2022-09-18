// 36. Valid Sudoku
// https://leetcode.com/problems/valid-sudoku/

using namespace std;

#include <set>
#include <vector>

class Solution {
public:
  bool isValidSudoku(vector<vector<char>> &board) {
    vector<set<char>> sets(27);

    for (int i = 0; i < 9; i++) {
      for (int j = 0; j < 9; j++) {
        int hor = i, vert = 9 + j, cell = 18 + (i / 3) * 3 + (j / 3);
        if (board[i][j] != '.') {
          pair<set<char>::iterator, bool> hor_result =
              sets[hor].insert(board[i][j]);
          pair<set<char>::iterator, bool> vert_result =
              sets[vert].insert(board[i][j]);
          pair<set<char>::iterator, bool> cell_result =
              sets[cell].insert(board[i][j]);
          if (!hor_result.second || !vert_result.second ||
              !cell_result.second) {
            return false;
          }
        }
      }
    }

    return true;
  }
};

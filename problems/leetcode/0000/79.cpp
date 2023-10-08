// 79. Word Search
// https://leetcode.com/problems/word-search/description/

using namespace std;

#include <string>
#include <vector>

class Solution {
public:
  const int dx[4] = {1, -1, 0, 0};
  const int dy[4] = {0, 0, 1, -1};

  bool dfs(vector<vector<char>> &board, vector<vector<bool>> &visited,
           string &word, int m, int n, int x, int y, int index) {
    if (index < word.size() && board[x][y] != word[index]) {
      return false;
    }

    if (index == word.size() - 1) {
      return board[x][y] == word[index];
    }

    visited[x][y] = true;

    bool result = false;
    for (int i = 0; i < 4; i++) {
      int newX = x + dx[i], newY = y + dy[i];
      if (0 <= newX && newX < m && 0 <= newY && newY < n &&
          !visited[newX][newY]) {
        result =
            result || dfs(board, visited, word, m, n, newX, newY, index + 1);
      }
    }

    visited[x][y] = false;

    return result;
  }

  bool exist(vector<vector<char>> &board, string word) {
    int m = board.size(), n = board[0].size();
    vector<vector<bool>> visited(m, vector<bool>(n, false));

    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (dfs(board, visited, word, m, n, i, j, 0)) {
          return true;
        }
      }
    }

    return false;
  }
};

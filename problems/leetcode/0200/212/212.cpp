// 212. Word Search II
// https://leetcode.com/problems/word-search-ii/description/

using namespace std;

#include <string>
#include <unordered_set>
#include <vector>

class TrieNode {
public:
  bool end = false;
  TrieNode *nodes['z' - 'a' + 1];

  TrieNode() {
    for (int i = 0; i < 'z' - 'a' + 1; i++) {
      nodes[i] = nullptr;
    }
  }
};

class Solution {
public:
  const int dr[4] = {0, 0, 1, -1};
  const int dc[4] = {1, -1, 0, 0};

  TrieNode *root = new TrieNode();
  int m = 0, n = 0;
  unordered_set<string> found;
  vector<vector<bool>> visited;

  bool isValidCoordinate(int r, int c) {
    return 0 <= r && r < m && 0 <= c && c < n;
  }

  void insert(string &s) {
    TrieNode *node = root;

    for (char ch : s) {
      if (!node->nodes[ch - 'a']) {
        node->nodes[ch - 'a'] = new TrieNode();
      }
      node = node->nodes[ch - 'a'];
    }

    node->end = true;
  }

  void dfs(vector<vector<char>> &board, int r, int c, TrieNode *node,
           string &current) {
    if (!node->nodes[board[r][c] - 'a']) {
      return;
    }

    current.push_back(board[r][c]);
    visited[r][c] = true;

    TrieNode *next = node->nodes[board[r][c] - 'a'];
    if (next->end) {
      found.insert(current);
    }

    for (int i = 0; i < 4; i++) {
      int newR = r + dr[i], newC = c + dc[i];
      if (isValidCoordinate(newR, newC) && !visited[newR][newC]) {
        dfs(board, newR, newC, next, current);
      }
    }

    current.pop_back();
    visited[r][c] = false;
  }

  vector<string> findWords(vector<vector<char>> &board, vector<string> &words) {
    m = board.size();
    n = board[0].size();
    visited = vector<vector<bool>>(m, vector<bool>(n, false));

    for (string &word : words) {
      insert(word);
    }

    string current;
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        dfs(board, i, j, root, current);
      }
    }

    return vector<string>(found.begin(), found.end());
  }
};

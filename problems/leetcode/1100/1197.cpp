// 1197. Minimum Knight Moves
// https://leetcode.com/problems/minimum-knight-moves/description/

using namespace std;

#include <unordered_map>

class Solution {
public:
  unordered_map<int, unordered_map<int, int>> memo;

  int dfs(int x, int y) {
    if (memo[x][y] != 0) {
      return memo[x][y];
    }

    if (x + y == 0) {
      return 0;
    }

    if (x + y == 2) {
      return 2;
    }

    memo[x][y] =
        1 + min(dfs(abs(x - 1), abs(y - 2)), dfs(abs(x - 2), abs(y - 1)));
    return memo[x][y];
  }

  int minKnightMoves(int x, int y) { return dfs(abs(x), abs(y)); }
};

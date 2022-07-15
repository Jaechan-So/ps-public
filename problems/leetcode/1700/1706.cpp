// 1706. Where Will the Ball Fall
// https://leetcode.com/problems/where-will-the-ball-fall/

using namespace std;

#include <vector>

class Solution {
public:
  vector<int> findBall(vector<vector<int>> &grid) {
    vector<int> answer;
    int m = grid.size(), n = grid[0].size();

    for (int i = 0; i < n; i++) {
      int column = i;

      bool stuck = false;
      for (int row = 0; row < m; row++) {
        bool isLeftSideStuck = ((column == 0) && (grid[row][column] == -1));
        bool isRightSideStuck = ((column == n - 1) && (grid[row][column] == 1));
        bool isVStuck =
            ((column != n - 1) &&
             (grid[row][column] == 1 && grid[row][column + 1] == -1)) ||
            ((column != 0) &&
             (grid[row][column] == -1 && grid[row][column - 1] == 1));

        stuck = isLeftSideStuck || isRightSideStuck || isVStuck;

        if (stuck) {
          answer.push_back(-1);
          break;
        }

        column = grid[row][column] == 1 ? column + 1 : column - 1;
      }

      if (!stuck) {
        answer.push_back(column);
      }
    }

    return answer;
  }
};

// 1901. Find a Peak Element II
// https://leetcode.com/problems/find-a-peak-element-ii/

using namespace std;

#include <vector>

class Solution {
public:
  vector<int> findPeakGrid(vector<vector<int>> &mat) {
    int startColumn = 0, endColumn = mat[0].size() - 1;

    while (startColumn <= endColumn) {
      int midColumn = (startColumn + endColumn) / 2, maxRow = 0;

      for (int i = 0; i < mat.size(); i++) {
        maxRow = mat[i][midColumn] >= mat[maxRow][midColumn] ? i : maxRow;
      }

      bool biggerThanLeft =
          (midColumn == startColumn ||
           mat[maxRow][midColumn - 1] < mat[maxRow][midColumn]);
      bool biggerThanRight =
          (midColumn == endColumn ||
           mat[maxRow][midColumn] > mat[maxRow][midColumn + 1]);

      if (biggerThanLeft && biggerThanRight) {
        return vector<int>({maxRow, midColumn});
      }

      if (biggerThanLeft) {
        startColumn = midColumn + 1;
      } else {
        endColumn = midColumn - 1;
      }
    }

    return vector<int>({-1, -1});
  }
};

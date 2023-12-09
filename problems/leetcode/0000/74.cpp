// 74. Search a 2D Matrix
// https://leetcode.com/problems/search-a-2d-matrix/description/

using namespace std;

#include <vector>

class Solution {
public:
  bool searchMatrix(vector<vector<int>> &matrix, int target) {
    int m = matrix.size(), n = matrix[0].size(), start = 0, end = (m * n) - 1;

    while (start < end) {
      int mid = (start + end) / 2;
      if (matrix[mid / n][mid % n] < target) {
        start = mid + 1;
      } else {
        end = mid;
      }
    }

    return matrix[end / n][end % n] == target;
  }
};

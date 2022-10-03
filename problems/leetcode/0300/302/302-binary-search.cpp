// 302. Smallest Rectangle Enclosing Black Pixels
// https://leetcode.com/problems/smallest-rectangle-enclosing-black-pixels/

using namespace std;

#include <vector>

class Solution {
public:
  int minArea(vector<vector<char>> &image, int x, int y) {
    pair<int, int> rowBoundary = getRowBoundary(image, x);
    pair<int, int> columnBoundary = getColumnBoundary(image, y);
    return (rowBoundary.second - rowBoundary.first) *
           (columnBoundary.second - columnBoundary.first);
  }

  pair<int, int> getRowBoundary(vector<vector<char>> &image, int x) {
    pair<int, int> rowBoundary = {0, 0};

    int start = 0, end = x;
    while (start < end) {
      int mid = (start + end) / 2;
      if (isIncludeBlackPixelInRow(image, mid)) {
        end = mid;
      } else {
        start = mid + 1;
      }
    }
    rowBoundary.first = start;

    start = x, end = image.size();
    while (start < end) {
      int mid = (start + end) / 2;
      if (isIncludeBlackPixelInRow(image, mid)) {
        start = mid + 1;
      } else {
        end = mid;
      }
    }
    rowBoundary.second = start;

    return rowBoundary;
  }

  bool isIncludeBlackPixelInRow(vector<vector<char>> &image, int i) {
    for (int j = 0; j < image[0].size(); j++) {
      if (image[i][j] == '1') {
        return true;
      }
    }

    return false;
  }

  pair<int, int> getColumnBoundary(vector<vector<char>> &image, int y) {
    pair<int, int> columnBoundary = {0, 0};

    int start = 0, end = y;
    while (start < end) {
      int mid = (start + end) / 2;
      if (isIncludeBlackPixelInColumn(image, mid)) {
        end = mid;
      } else {
        start = mid + 1;
      }
    }
    columnBoundary.first = start;

    start = y, end = image[0].size();
    while (start < end) {
      int mid = (start + end) / 2;
      if (isIncludeBlackPixelInColumn(image, mid)) {
        start = mid + 1;
      } else {
        end = mid;
      }
    }
    columnBoundary.second = start;

    return columnBoundary;
  }

  bool isIncludeBlackPixelInColumn(vector<vector<char>> &image, int j) {
    for (int i = 0; i < image.size(); i++) {
      if (image[i][j] == '1') {
        return true;
      }
    }

    return false;
  }
};

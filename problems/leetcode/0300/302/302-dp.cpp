// 302. Smallest Rectangle Enclosing Black Pixels
// https://leetcode.com/problems/smallest-rectangle-enclosing-black-pixels/

using namespace std;

#include <vector>

class Solution {
public:
  const int differenceX[4] = {0, 0, 1, -1}, differenceY[4] = {1, -1, 0, 0};
  int minX = 100, maxX = -1, minY = 100, maxY = -1;

  int minArea(vector<vector<char>> &image, int x, int y) {
    dfs(image, x, y);
    return (maxX - minX + 1) * (maxY - minY + 1);
  }

  void dfs(vector<vector<char>> &image, int i, int j) {
    // Already visited
    if (image[i][j] == '0') {
      return;
    }

    // Visit pixel
    image[i][j] = '0';
    minX = min(minX, i);
    maxX = max(maxX, i);
    minY = min(minY, j);
    maxY = max(maxY, j);

    for (int k = 0; k < 4; k++) {
      int newI = i + differenceX[k], newJ = j + differenceY[k];
      if (isValidPixel(image, newI, newJ)) {
        dfs(image, newI, newJ);
      }
    }
  }

  bool isValidPixel(vector<vector<char>> &image, int i, int j) {
    return (i >= 0) && (i < image.size()) && (j >= 0) && (j < image[0].size());
  }
};

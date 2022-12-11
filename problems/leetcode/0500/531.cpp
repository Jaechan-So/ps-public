// 531. Lonely Pixel I
// https://leetcode.com/problems/lonely-pixel-i/description/

using namespace std;

#include <map>
#include <vector>

class Solution {
public:
  int findLonelyPixel(vector<vector<char>> &picture) {
    int m = picture.size(), n = picture[0].size();
    map<int, int> blackCountByRow, blackCountByColumn;

    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (picture[i][j] == 'B') {
          blackCountByRow[i]++;
          blackCountByColumn[j]++;
        }
      }
    }

    int lonelyBlacks = 0;

    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (picture[i][j] == 'B' && blackCountByRow[i] == 1 &&
            blackCountByColumn[j] == 1) {
          lonelyBlacks++;
        }
      }
    }

    return lonelyBlacks;
  }
};

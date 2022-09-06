// 1465. Maximum Area of a Piece of Cake After Horizontal and Vertical Cuts
// https://leetcode.com/problems/maximum-area-of-a-piece-of-cake-after-horizontal-and-vertical-cuts/

using namespace std;

#include <vector>

typedef long long ll;

class Solution {
public:
  int maxArea(int h, int w, vector<int> &horizontalCuts,
              vector<int> &verticalCuts) {
    sort(horizontalCuts.begin(), horizontalCuts.end());
    sort(verticalCuts.begin(), verticalCuts.end());

    int maxHorizontalDiff = horizontalCuts[0],
        maxVerticalDiff = verticalCuts[0];
    for (int i = 1; i < horizontalCuts.size(); i++) {
      maxHorizontalDiff =
          max(maxHorizontalDiff, horizontalCuts[i] - horizontalCuts[i - 1]);
    }
    maxHorizontalDiff =
        max(maxHorizontalDiff, h - horizontalCuts[horizontalCuts.size() - 1]);
    for (int i = 1; i < verticalCuts.size(); i++) {
      maxVerticalDiff =
          max(maxVerticalDiff, verticalCuts[i] - verticalCuts[i - 1]);
    }
    maxVerticalDiff =
        max(maxVerticalDiff, w - verticalCuts[verticalCuts.size() - 1]);

    return getModuloOf((ll)maxHorizontalDiff * (ll)maxVerticalDiff);
  }

  int getModuloOf(ll num) { return (int)(num % 1000000007); }
};

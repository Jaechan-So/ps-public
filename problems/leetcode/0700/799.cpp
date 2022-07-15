// 799. Champagne Tower
// https://leetcode.com/problems/champagne-tower/

using namespace std;

class Solution {
public:
  double glasses[101][101];

  void fillAndDistributeLiquid(int i, int j, double remainingLiquid) {
    if (i > 99) {
      return;
    }
    if (glasses[i][j] + remainingLiquid <= 1) {
      glasses[i][j] += remainingLiquid;
      return;
    }
    double liquidAmountForDistribute =
        (remainingLiquid - (1 - glasses[i][j])) / 2;
    glasses[i][j] = 1;
    fillAndDistributeLiquid(i + 1, j, liquidAmountForDistribute);
    fillAndDistributeLiquid(i + 1, j + 1, liquidAmountForDistribute);
  }

  double champagneTower(int poured, int query_row, int query_glass) {
    glasses[0][0] = poured;
    for (int i = 0; i <= query_row; i++) {
      for (int j = 0; j <= i; j++) {
        if (glasses[i][j] > 1) {
          double liquidAmountForDistribute = (glasses[i][j] - 1) / 2;
          glasses[i + 1][j] += liquidAmountForDistribute;
          glasses[i + 1][j + 1] += liquidAmountForDistribute;
          glasses[i][j] = 1;
        }
      }
    }
    return glasses[query_row][query_glass];
  }
};

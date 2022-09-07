// 518. Coin Change II
// https://leetcode.com/problems/coin-change-ii/

using namespace std;

#include <vector>

class Solution {
public:
  int change(int amount, vector<int> &coins) {
    // first index i: use coins[0] to coins[i]
    // second index j: of amount j
    int changes[300][5001] = {
        0,
    };

    for (int i = 0; i < coins.size(); i++) {
      changes[i][0] = 1;
    }

    for (int i = coins[0]; i <= amount; i += coins[0]) {
      changes[0][i] = 1;
    }

    for (int i = 1; i < coins.size(); i++) {
      for (int j = 0; j <= amount; j++) {
        int currentCoin = coins[i], currentAmount = j, currentChanges = 0;
        while (currentAmount >= 0) {
          currentChanges += changes[i - 1][currentAmount];
          currentAmount -= currentCoin;
        }
        changes[i][j] = currentChanges;
      }
    }

    return changes[coins.size() - 1][amount];
  }
};

// 875. Koko Eating Bananas
// https://leetcode.com/problems/koko-eating-bananas/

using namespace std;

#include <utility>
#include <vector>

class Solution {
public:
  int minEatingSpeed(vector<int> &piles, int h) {
    int maxBananaCount = 0;
    for (auto &pile : piles) {
      maxBananaCount = max(maxBananaCount, pile);
    }

    int left = 1, right = maxBananaCount, k = (1 + maxBananaCount) / 2;
    while (left != right) {
      int spentTime = 0;
      for (auto &pile : piles) {
        spentTime += ((pile - 1) / k) + 1;
      }

      if (spentTime <= h) {
        // We should decrease k.
        right = k;
      } else {
        // We should increase k.
        // Here we check left == k due to avoid infinite loop.
        left = left == k ? k + 1 : k;
      }
      k = (left + right) / 2;
    }

    return k;
  }
};

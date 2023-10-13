// 904. Fruit Into Baskets
// https://leetcode.com/problems/fruit-into-baskets/description/

using namespace std;

#include <vector>

class Solution {
public:
  int totalFruit(vector<int> &fruits) {
    int n = fruits.size(), prevIndex = -1;
    int lastIndex1 = 0, lastType1 = fruits[0], lastIndex2 = -1, lastType2 = -1,
        index = 1, maxFruits = 1;

    while (index < n) {
      if (fruits[index] == lastType1) {
        lastIndex1 = index;
      } else if (lastType2 == -1) {
        lastType2 = fruits[index];
        lastIndex2 = index;
      } else if (lastType2 == fruits[index]) {
        lastIndex2 = index;
      } else {
        if (lastIndex1 < lastIndex2) {
          prevIndex = lastIndex1;
          lastIndex1 = index;
          lastType1 = fruits[index];
        } else {
          prevIndex = lastIndex2;
          lastIndex2 = index;
          lastType2 = fruits[index];
        }
      }

      maxFruits = max(maxFruits, index - prevIndex);
      index++;
    }

    return maxFruits;
  }
};

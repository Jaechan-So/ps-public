// 343. Integer Break
// https://leetcode.com/problems/integer-break/description/

using namespace std;

#include <vector>

class Solution {
public:
  vector<int> maxProduct;

  int getMaxProduct(int n) {
    if (maxProduct[n] != -1) {
      return maxProduct[n];
    }

    int product = INT_MIN;
    for (int i = 1; n - i >= 1; i++) {
      product = max(product, i * max(n - i, getMaxProduct(n - i)));
    }

    maxProduct[n] = product;
    return product;
  }

  int integerBreak(int n) {
    maxProduct = vector<int>(n + 1, -1);
    maxProduct[1] = 1;

    return getMaxProduct(n);
  }
};

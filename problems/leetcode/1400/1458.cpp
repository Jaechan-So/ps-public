// 1458. Max Dot Product of Two Subsequences
// https://leetcode.com/problems/max-dot-product-of-two-subsequences/description/

using namespace std;

#include <vector>

class Solution {
public:
  int maxDotProduct(vector<int> &nums1, vector<int> &nums2) {
    int n1 = nums1.size(), n2 = nums2.size();
    vector<int> products(n1, 0);
    products[0] = nums1[0] * nums2[0];
    for (int i = 1; i < n1; i++) {
      products[i] = max(products[i - 1], nums1[i] * nums2[0]);
    }

    for (int i = 1; i < n2; i++) {
      vector<int> newProducts(products);

      newProducts[0] = max(newProducts[0], nums1[0] * nums2[i]);
      for (int j = 1; j < n1; j++) {
        newProducts[j] = max(newProducts[j], newProducts[j - 1]);
        newProducts[j] = max(newProducts[j],
                             (nums1[j] * nums2[i]) + max(0, products[j - 1]));
      }

      products = newProducts;
    }

    return products[n1 - 1];
  }
};

// 1. Naive: O(n * (4 ^ n))

// 2. DP?
// dp[i][j] = nums1[i]와 nums2[j]가 마지막 원소로써 곱해지는 최대 product
// dp[i][j] = max_(k = 1 to i)(nums1[k] * nums2[j] + dp[k - 1][j - 1]), dp[k][j
// - 1]

// 72 + 3 + 80 + 45 -> [-8, 3, -10, 9], [-9, 1, -8, 5]

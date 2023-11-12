// 1359. Count All Valid Pickup and Delivery Options
// https://leetcode.com/problems/count-all-valid-pickup-and-delivery-options/description/

class Solution {
public:
  const int mod = 1e9 + 7;

  int countOrders(int n) {
    long long count = 1;

    for (int i = 1; i <= n; i++) {
      count *= ((2 * i * ((2 * i) - 1)) / 2);
      count %= mod;
    }

    return (int)count;
  }
};

// (Pi_(i = 1)^(n))(2i C 2)

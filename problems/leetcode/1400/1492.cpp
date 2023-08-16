// 1492. The kth Factor of n
// https://leetcode.com/problems/the-kth-factor-of-n/description

using namespace std;

#include <utility>
#include <vector>

class Solution {
public:
  int kthFactor(int n, int k) {
    vector<int> factors;

    for (int i = 1; pow(i, 2) <= n; i++) {
      if (n % i == 0) {
        factors.push_back(i);
      }
    }

    if (k <= factors.size()) {
      return factors[k - 1];
    } else {
      bool isSquare = pow(factors.back(), 2) == n;
      int diff = k - factors.size();
      int index = factors.size() - diff - (isSquare ? 1 : 0);
      return index >= 0 ? n / factors[index] : -1;
    }
  }
};

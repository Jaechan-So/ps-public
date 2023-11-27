// 50. Pow(x, n)
// https://leetcode.com/problems/powx-n/description/

class Solution {
public:
  double myPow(double x, int n) {
    long long e = n;

    if (e == 0) {
      return 1;
    }

    if (e < 0) {
      x = (1 / x);
      e *= -1;
    }

    double result = 1;
    while (e) {
      if (e % 2 == 1) {
        result *= x;
        e -= 1;
      }
      x *= x;
      e /= 2;
    }

    return result;
  }
};

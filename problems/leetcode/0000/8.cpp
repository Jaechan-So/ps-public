// 8. String to Integer (atoi)
// https://leetcode.com/problems/string-to-integer-atoi/description/

using namespace std;

#include <string>

class Solution {
public:
  int myAtoi(string s) {
    int index = 0, n = s.size();

    while (index < n) {
      if (s[index] != ' ') {
        break;
      }
      index++;
    }

    if (index == n || !(s[index] == '-' || s[index] == '+' ||
                        ('0' <= s[index] && s[index] <= '9'))) {
      return 0;
    }

    bool positive = true;
    if (s[index] == '-') {
      positive = false;
    }
    if (s[index] == '-' || s[index] == '+') {
      index++;
    }

    long long value = 0;
    while ('0' <= s[index] && s[index] <= '9') {
      long long incr = s[index] - '0';
      long long nextValue = (value * 10) + (positive ? incr : -incr);

      if (nextValue < (long long)INT_MIN) {
        return INT_MIN;
      }

      if (nextValue > (long long)INT_MAX) {
        return INT_MAX;
      }

      value = nextValue;
      index++;
    }

    return (int)value;
  }
};

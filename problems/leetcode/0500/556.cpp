// 556. Next Greater Element III
// https://leetcode.com/problems/next-greater-element-iii/

using namespace std;

#include <algorithm>

class Solution {
public:
  int nextGreaterElement(int n) {
    // From least significant bit, find first bit which becomes smaller than
    // previous bit. Find first bigger digit than that digit. Draw it to the
    // first digit of part. For the rest of digits, just sort it by ascending
    // order.

    int digits[32];
    int quotient = n, index = 0;
    while (quotient > 0) {
      digits[index++] = quotient % 10;
      quotient /= 10;
    }

    int i = 1;
    bool satisfied = false;
    for (; i < index; i++) {
      if (digits[i - 1] > digits[i]) {
        satisfied = true;
        break;
      }
    }
    if (!satisfied) {
      return -1;
    }

    for (int j = 0; j < i; j++) {
      if (digits[j] > digits[i]) {
        swap(digits[j], digits[i]);
        break;
      }
    }

    sort(digits, digits + i, greater<int>());

    long long answer = 0, exponent = 1;
    for (int k = 0; k < index; k++) {
      answer += (digits[k] * exponent);
      exponent *= 10;
    }

    return answer > INT_MAX ? -1 : answer;
  }
};

// 670. Maximum Swap
// https://leetcode.com/problems/maximum-swap/

using namespace std;

#include <vector>

class Solution {
public:
  int maximumSwap(int num) {
    vector<int> digits, sortedDigits;

    int quotient = num;
    while (quotient > 0) {
      int remainder = quotient % 10;
      digits.push_back(remainder);
      sortedDigits.push_back(remainder);

      quotient /= 10;
    }

    sort(sortedDigits.begin(), sortedDigits.end(), less<int>());

    for (int i = digits.size() - 1; i >= 0; i--) {
      if (digits[i] != sortedDigits[i]) {
        for (int j = 0; j < digits.size(); j++) {
          if (digits[j] == sortedDigits[i]) {
            swap(digits[i], digits[j]);
            break;
          }
        }
        break;
      }
    }

    int exponent = 1, answer = 0;
    for (int digit : digits) {
      answer += digit * exponent;
      exponent *= 10;
    }

    return answer;
  }
};

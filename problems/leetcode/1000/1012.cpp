// 1012. Numbers With Repeated Digits
// https://leetcode.com/problems/numbers-with-repeated-digits/description/

using namespace std;

#include <unordered_set>
#include <vector>

class Solution {
public:
  void getDigitsInner(int n, vector<int> &result) {
    if (n == 0) {
      return;
    }

    int quotient = n / 10, remainder = n % 10;
    getDigitsInner(quotient, result);
    result.push_back(remainder);
  }

  vector<int> getDigits(int n) {
    vector<int> result;
    getDigitsInner(n, result);
    return result;
  }

  int numNonRepeatedDigitsAtN(int n) {
    vector<int> digits = getDigits(n);
    unordered_set<int> occurred;

    int totalCount = 0;
    for (int i = 0; i < digits.size(); i++) {
      int count = 0;
      for (int j = 0; j < digits[i]; j++) {
        if (i == 0 && j == 0) {
          continue;
        }
        if (occurred.find(j) == occurred.end()) {
          count++;
        }
      }

      int product = 1;
      for (int j = i + 1; j < digits.size(); j++) {
        int diff = j - (i + 1);
        product *= (9 - occurred.size() - diff);
      }
      totalCount += (product * count);

      if (occurred.find(digits[i]) != occurred.end()) {
        break;
      }
      occurred.insert(digits[i]);
    }

    return totalCount + (occurred.size() == digits.size() ? 1 : 0);
  }

  int numDupDigitsAtMostN(int n) {
    if (n < 10) {
      return 0;
    }

    int digits = 0, num = n;
    while (num > 0) {
      num /= 10;
      digits++;
    }

    int nonRepeatedDigits = min(n, 9), count = 9;
    for (int d = 2; d < digits; d++) {
      count *= (9 - d + 2);
      nonRepeatedDigits += count;
    }

    nonRepeatedDigits += numNonRepeatedDigitsAtN(n);
    return n - nonRepeatedDigits;
  }
};

// 1. 모두 다른 숫자로 이루어진 숫자의 개수를 빼는 쪽으로 생각해본다.
// 2. k자리의 숫자 -> 9 * 9 * 8 * 7 * ...
// 3. 최대자리의 숫자 -> Backtracking?

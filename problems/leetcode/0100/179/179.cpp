// 179. Largest Number
// https://leetcode.com/problems/largest-number/description/

using namespace std;

#include <string>

int getDigitCount(int n) {
  int digit = 0;

  while (n > 0) {
    n /= 10;
    digit++;
  }

  return digit;
}

struct DigitComparator {
  bool operator()(int n1, int n2) {
    if (n1 == 0) {
      return false;
    }
    if (n2 == 0) {
      return true;
    }

    int digit1 = getDigitCount(n1), digit2 = getDigitCount(n2);

    return (n1 * pow(10, digit2)) + n2 > (n2 * pow(10, digit1)) + n1;
  }
};

class Solution {
public:
  void push(string &s, int n) {
    if (n == 0) {
      return;
    }

    push(s, n / 10);
    s.push_back('0' + (n % 10));
  }

  string largestNumber(vector<int> &nums) {
    sort(nums.begin(), nums.end(), DigitComparator());

    string result;

    for (int num : nums) {
      if (num == 0) {
        result.push_back('0');
      } else {
        push(result, num);
      }
    }

    return result[0] == '0' ? "0" : result;
  }
};

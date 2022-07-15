// 66. Plus One
// https://leetcode.com/problems/plus-one/

using namespace std;

#include <vector>

class Solution {
public:
  vector<int> plusOne(vector<int> &digits) {
    vector<int> digitsRev;
    bool carry = true;
    for (int i = digits.size() - 1; i >= 0; i--) {
      if (carry) {
        if (digits[i] == 9) {
          carry = true;
          digitsRev.push_back(0);
        } else {
          carry = false;
          digitsRev.push_back(digits[i] + 1);
        }
      } else {
        digitsRev.push_back(digits[i]);
      }
    }
    if (carry) {
      digitsRev.push_back(1);
    }

    vector<int> digitsRevRev;
    for (int i = 0; i < digitsRev.size(); i++) {
      digitsRevRev.push_back(digitsRev[digitsRev.size() - i - 1]);
    }
    return digitsRevRev;
  }
};

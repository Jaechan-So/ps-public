// 784. Letter Case Permutation
// https://leetcode.com/problems/letter-case-permutation/description/

using namespace std;

#include <string>
#include <vector>

class Solution {
public:
  vector<string> letterCasePermutation(string s) {
    vector<string> cases;
    traverseCases(s, cases, 0);
    return cases;
  }

  void traverseCases(string &s, vector<string> &cases, int index) {
    if (index >= s.size()) {
      cases.push_back(string(s));
      return;
    }

    if (isdigit(s[index])) {
      traverseCases(s, cases, index + 1);
      return;
    }

    traverseCases(s, cases, index + 1);
    if ('a' <= s[index] && s[index] <= 'z') {
      s[index] = toupper(s[index]);
      traverseCases(s, cases, index + 1);
      s[index] = tolower(s[index]);
    } else {
      s[index] = tolower(s[index]);
      traverseCases(s, cases, index + 1);
      s[index] = toupper(s[index]);
    }
    return;
  }
};

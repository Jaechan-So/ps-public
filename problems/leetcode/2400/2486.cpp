// 2486. Append Characters to String to Make Subsequence
// https://leetcode.com/problems/append-characters-to-string-to-make-subsequence/description

using namespace std;

#include <string>

class Solution {
public:
  int appendCharacters(string s, string t) {
    int i = 0;

    for (char ch : s) {
      if (i < t.size() && t[i] == ch) {
        i++;
      }
    }

    return t.size() - i;
  }
};

// 921. Minimum Add to Make Parentheses Valid
// https://leetcode.com/problems/minimum-add-to-make-parentheses-valid/description/

using namespace std;

#include <string>

class Solution {
public:
  int minAddToMakeValid(string s) {
    int diff = 0, add = 0;

    for (char ch : s) {
      diff += (ch == '(' ? 1 : -1);

      if (diff == -1) {
        add++;
        diff++;
      }
    }

    return add + diff;
  }
};

// 1249. Minimum Remove to Make Valid Parentheses
// https://leetcode.com/problems/minimum-remove-to-make-valid-parentheses/

using namespace std;

#include <string>

class Solution {
public:
  string minRemoveToMakeValid(string s) {
    string answer, rightParenthesesRemoved;
    int leftParenthesesCount = 0;

    for (auto &ch : s) {
      if (ch == ')') {
        if (leftParenthesesCount == 0) {
          continue;
        }
        leftParenthesesCount--;
      }
      if (ch == '(') {
        leftParenthesesCount++;
      }
      rightParenthesesRemoved.push_back(ch);
    }

    int needRemoveLeftParenthesesIndex = 0;
    for (int i = rightParenthesesRemoved.size() - 1; i >= 0; i--) {
      if (rightParenthesesRemoved[i] == '(') {
        leftParenthesesCount--;
      }
      if (leftParenthesesCount == 0) {
        needRemoveLeftParenthesesIndex = i;
        break;
      }
    }

    for (int i = 0; i < rightParenthesesRemoved.size(); i++) {
      if (rightParenthesesRemoved[i] == '(' &&
          i >= needRemoveLeftParenthesesIndex) {
        continue;
      }
      answer.push_back(rightParenthesesRemoved[i]);
    }

    return answer;
  }
};

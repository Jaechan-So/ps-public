// 20. Valid Parentheses
// https://leetcode.com/problems/valid-parentheses/

using namespace std;

#include <stack>
#include <string>

class Solution {
public:
  bool isParenthesisMatched(char c1, char c2) {
    return (c1 == '(' && c2 == ')') || (c1 == '{' && c2 == '}') ||
           (c1 == '[' && c2 == ']');
  }

  bool isValid(string s) {
    stack<char> st;

    for (string::iterator iter = s.begin(); iter != s.end(); iter++) {
      if (!st.empty() && isParenthesisMatched(st.top(), *iter)) {
        st.pop();
      } else {
        st.push(*iter);
      }
    }

    return st.empty();
  }
};

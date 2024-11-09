// 22. Generate Parentheses
// https://leetcode.com/problems/generate-parentheses/

using namespace std;

#include <string>
#include <vector>

class Solution {
public:
  int pairs;
  vector<string> answer;
  void bt(string &prev, int left, int right) {
    if (left + right == 2 * pairs) {
      answer.push_back(prev);
      return;
    }
    if (left < pairs) {
      string left_str = prev;
      left_str.push_back('(');
      bt(left_str, left + 1, right);
    }
    if (right < pairs && left > right) {
      string right_str = prev;
      right_str.push_back(')');
      bt(right_str, left, right + 1);
    }
  }
  vector<string> generateParenthesis(int n) {
    pairs = n;
    string init_str = "";
    bt(init_str, 0, 0);
    return answer;
  }
};

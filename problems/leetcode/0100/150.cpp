// 150. Evaluate Reverse Polish Notation
// https://leetcode.com/problems/evaluate-reverse-polish-notation/

using namespace std;

#include <stack>
#include <string>
#include <vector>

class Solution {
public:
  int evalRPN(vector<string> &tokens) {
    string plus = "+";
    string minus = "-";
    string multiply = "*";
    string divide = "/";

    stack<int> evalResults;

    for (int i = 0; i < tokens.size(); i++) {
      string &token = tokens[i];

      if (token.compare(plus) == 0) {
        int first = evalResults.top();
        evalResults.pop();
        int second = evalResults.top();
        evalResults.pop();
        evalResults.push(second + first);
      } else if (token.compare(minus) == 0) {
        int first = evalResults.top();
        evalResults.pop();
        int second = evalResults.top();
        evalResults.pop();
        evalResults.push(second - first);
      } else if (token.compare(multiply) == 0) {
        int first = evalResults.top();
        evalResults.pop();
        int second = evalResults.top();
        evalResults.pop();
        evalResults.push(second * first);
      } else if (token.compare(divide) == 0) {
        int first = evalResults.top();
        evalResults.pop();
        int second = evalResults.top();
        evalResults.pop();
        evalResults.push(second / first);
      } else {
        evalResults.push(stoi(token));
      }
    }

    return evalResults.top();
  }
};

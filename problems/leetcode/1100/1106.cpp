// 1106. Parsing A Boolean Expression
// https://leetcode.com/problems/parsing-a-boolean-expression/description/

using namespace std;

#include <string>

class Solution {
public:
  pair<int, bool> parseBoolExprRecur(string &expression, int index) {
    switch (expression[index]) {
    case 't':
      return {index + 1, true};
    case 'f':
      return {index + 1, false};
    case '!': {
      pair<int, bool> innerResult = parseBoolExprRecur(expression, index + 2);
      return {innerResult.first + 1, !innerResult.second};
    }
    case '&': {
      int curr = index + 2;
      bool result = true;

      while (expression[curr] != ')') {
        pair<int, bool> innerResult = parseBoolExprRecur(expression, curr);
        result = result && innerResult.second;
        curr = innerResult.first;
        if (curr < expression.size() && expression[curr] == ',') {
          curr++;
        }
      }

      return {curr + 1, result};
    }
    case '|': {
      int curr = index + 2;
      bool result = false;

      while (expression[curr] != ')') {
        pair<int, bool> innerResult = parseBoolExprRecur(expression, curr);
        result = result || innerResult.second;
        curr = innerResult.first;
        if (curr < expression.size() && expression[curr] == ',') {
          curr++;
        }
      }

      return {curr + 1, result};
    }
    default:
      break;
    }

    return {0, false};
  }

  bool parseBoolExpr(string expression) {
    return parseBoolExprRecur(expression, 0).second;
  }
};

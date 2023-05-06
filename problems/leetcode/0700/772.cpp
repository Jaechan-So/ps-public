// Basic Calculator III
// https://leetcode.com/problems/basic-calculator-iii/description/

#include <string>
#include <vector>

using namespace std;

enum CalculatorState {
  BEFORE_START,
  NUMBER,
  ADD,
  SUBTRACT,
  MULTIPLY,
  DIVIDE,
  OPEN_PARENTHESIS,
  CLOSE_PARENTHESIS,
};

class Solution {
public:
  int calculateWithoutParentheses(vector<int> &numbers,
                                  vector<char> &operators) {
    vector<int> numbersAfterMulDiv;
    vector<char> operatorsAfterMulDiv;

    numbersAfterMulDiv.push_back(numbers[0]);
    for (int i = 0; i < operators.size(); i++) {
      if (operators[i] == '*' || operators[i] == '/') {
        int prevNum = numbersAfterMulDiv.back();
        numbersAfterMulDiv.pop_back();
        if (operators[i] == '*') {
          numbersAfterMulDiv.push_back(prevNum * numbers[i + 1]);
        } else {
          numbersAfterMulDiv.push_back(prevNum / numbers[i + 1]);
        }
      } else {
        numbersAfterMulDiv.push_back(numbers[i + 1]);
        operatorsAfterMulDiv.push_back(operators[i]);
      }
    }

    int result = numbersAfterMulDiv[0];
    for (int i = 0; i < operatorsAfterMulDiv.size(); i++) {
      if (operatorsAfterMulDiv[i] == '+') {
        result += numbersAfterMulDiv[i + 1];
      } else {
        result -= numbersAfterMulDiv[i + 1];
      }
    }
    return result;
  }

  int calculate(string s) {
    CalculatorState cs = BEFORE_START;
    int index = 0;

    vector<vector<int>> numbersInParentheses;
    numbersInParentheses.push_back(vector<int>());
    vector<vector<char>> operatorsInParentheses;
    operatorsInParentheses.push_back(vector<char>());

    while (index < s.size()) {
      switch (s[index]) {
      case '+':
        operatorsInParentheses.back().push_back('+');
        cs = ADD;
        break;
      case '-':
        operatorsInParentheses.back().push_back('-');
        cs = SUBTRACT;
        break;
      case '*':
        operatorsInParentheses.back().push_back('*');
        cs = MULTIPLY;
        break;
      case '/':
        operatorsInParentheses.back().push_back('/');
        cs = DIVIDE;
        break;
      case '(':
        numbersInParentheses.push_back(vector<int>());
        operatorsInParentheses.push_back(vector<char>());
        cs = OPEN_PARENTHESIS;
        break;
      case ')': {
        int innerResult = calculateWithoutParentheses(
            numbersInParentheses.back(), operatorsInParentheses.back());
        numbersInParentheses.pop_back();
        operatorsInParentheses.pop_back();
        numbersInParentheses.back().push_back(innerResult);
        cs = CLOSE_PARENTHESIS;
        break;
      }
      default:
        if (cs == NUMBER) {
          int prevNum = numbersInParentheses.back().back();
          numbersInParentheses.back().pop_back();
          numbersInParentheses.back().push_back(prevNum * 10 +
                                                (s[index] - '0'));
        } else {
          numbersInParentheses.back().push_back(s[index] - '0');
        }
        cs = NUMBER;
        break;
      }
      index++;
    }

    return calculateWithoutParentheses(numbersInParentheses.back(),
                                       operatorsInParentheses.back());
  }
};

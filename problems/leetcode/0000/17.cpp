// 17. Letter Combinations of a Phone Number
// https://leetcode.com/problems/letter-combinations-of-a-phone-number/

#include <map>
#include <string>
#include <vector>

using namespace std;

class Solution {
private:
  map<int, vector<char>> numberToCharacter;
  vector<string> answer;
  int digitsLength;

  void initMap() {
    for (int i = 2; i <= 6; i++) {
      vector<char> characters;
      for (int j = 0; j < 3; j++) {
        characters.push_back((i - 2) * 3 + j + 'a');
      }
      numberToCharacter.insert(make_pair(i, characters));
    }
    numberToCharacter.insert(make_pair(7, vector<char>({'p', 'q', 'r', 's'})));
    numberToCharacter.insert(make_pair(8, vector<char>({'t', 'u', 'v'})));
    numberToCharacter.insert(make_pair(9, vector<char>({'w', 'x', 'y', 'z'})));
  }

  int convertDigitIntoInteger(char c) { return c - '0'; }

  void parseDigit(string &currentString, string &digits, int index) {
    if (index >= digitsLength) {
      string answerString(currentString);
      answer.push_back(answerString);
      return;
    }
    for (auto &c : numberToCharacter[convertDigitIntoInteger(digits[index])]) {
      currentString.push_back(c);
      parseDigit(currentString, digits, index + 1);
      currentString.pop_back();
    }
  }

public:
  vector<string> letterCombinations(string digits) {
    digitsLength = digits.size();

    initMap();

    string currentString;
    if (digitsLength > 0) {
      parseDigit(currentString, digits, 0);
    }

    return answer;
  }
};

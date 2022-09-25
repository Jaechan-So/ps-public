// 791. Custom Sort String
// https://leetcode.com/problems/custom-sort-string/

using namespace std;

#include <string>

class Solution {
public:
  string customSortString(string order, string s) {
    bool isInOrder[26] = {
        false,
    };
    int existCount[26] = {
        0,
    };

    for (int i = 0; i < order.size(); i++) {
      isInOrder[convertCharToInt(order[i])] = true;
    }

    for (int i = 0; i < s.size(); i++) {
      existCount[convertCharToInt(s[i])]++;
    }

    string answer;
    for (auto &ch : order) {
      for (int i = 0; i < existCount[convertCharToInt(ch)]; i++) {
        answer.push_back(ch);
      }
    }
    for (int i = 0; i < 26; i++) {
      if (!isInOrder[i]) {
        for (int j = 0; j < existCount[i]; j++) {
          answer.push_back(convertIntToChar(i));
        }
      }
    }

    return answer;
  }

  int convertCharToInt(char ch) { return ch - 'a'; }

  char convertIntToChar(int i) { return 'a' + i; }
};

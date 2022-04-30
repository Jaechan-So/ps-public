// 2083. Substrings That Begin and End With the Same Letter
// https://leetcode.com/problems/substrings-that-begin-and-end-with-the-same-letter/

#include <string>
#include <unordered_map>

using namespace std;

class Solution {
 private:
  long long answer = 0;
  unordered_map<char, int> numberOfCharacters;

 public:
  long long numberOfSubstrings(string s) {
    for (auto& ch : s) {
      numberOfCharacters[ch]++;
    }

    for (auto& pair : numberOfCharacters) {
      long long numberOfCurrentCharacter = pair.second;
      long long possibleCasesWithCurrentCharacter =
          numberOfCurrentCharacter +
          (numberOfCurrentCharacter * (numberOfCurrentCharacter - 1) / 2);
      answer += possibleCasesWithCurrentCharacter;
    }

    return answer;
  }
};

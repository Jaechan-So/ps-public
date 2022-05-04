// 267. Palindrome Permutation II
// https://leetcode.com/problems/palindrome-permutation-ii/

#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
 private:
  const char invalidCharacter = '0';
  char middleCharacter = invalidCharacter;
  vector<string> answer;

  string generateReverse(const string& s) {
    string r;

    for (auto it = s.rbegin(); it != s.rend(); it++) {
      r.push_back(*it);
    }

    return r;
  }
  string constructResultString(string& currentString) {
    string resultString;

    resultString += currentString;
    if (middleCharacter != invalidCharacter) {
      resultString += middleCharacter;
    }
    resultString += generateReverse(currentString);

    return resultString;
  }
  void backtracking(unordered_map<char, int>& charCounts,
                    string& currentString) {
    int remainingCounts = 0;
    for (const auto& pair : charCounts) {
      remainingCounts += pair.second;
    }
    if (remainingCounts == 0) {
      string resultString = constructResultString(currentString);
      answer.push_back(resultString);
      return;
    }

    for (auto& pair : charCounts) {
      if (pair.second <= 0) {
        continue;
      }
      pair.second--;
      currentString.push_back(pair.first);

      backtracking(charCounts, currentString);

      currentString.pop_back();
      pair.second++;
    }
  }

 public:
  vector<string> generatePalindromes(string s) {
    unordered_map<char, int> charCounts;
    for (const auto& c : s) {
      charCounts[c]++;
    }

    for (auto& pair : charCounts) {
      if (pair.second % 2 == 1) {
        if (middleCharacter != invalidCharacter) {
          return answer;
        }
        middleCharacter = pair.first;
        pair.second--;
      }
    }

    for (auto& pair : charCounts) {
      pair.second /= 2;
    }

    string currentString;
    backtracking(charCounts, currentString);

    return answer;
  }
};

// 425. Word Squares
// https://leetcode.com/problems/word-squares/

using namespace std;

#include <map>
#include <string>
#include <vector>

class Solution {
public:
  vector<vector<string>> answer;
  int squareSize;
  map<string, vector<string>> prefixStrings;

  vector<vector<string>> wordSquares(vector<string> &words) {
    squareSize = words[0].size();
    prefixStrings = getPrefixStrings(words);

    for (auto &word : words) {
      vector<string> wordSquare({string(word)});
      backtracking(wordSquare, 1);
    }

    return answer;
  }

  map<string, vector<string>> getPrefixStrings(vector<string> &words) {
    map<string, vector<string>> prefixStrings;

    for (auto &word : words) {
      string prefix;
      for (int i = 0; i < squareSize - 1; i++) {
        prefix.push_back(word[i]);

        if (prefixStrings.find(prefix) != prefixStrings.end()) {
          prefixStrings[prefix].push_back(word);
        } else {
          vector<string> newPrefixString({word});
          prefixStrings.insert({string(prefix), newPrefixString});
        }
      }
    }

    return prefixStrings;
  }

  void backtracking(vector<string> &wordSquare, int step) {
    if (step == squareSize) {
      answer.push_back(vector<string>(wordSquare));
      return;
    }

    string prefix;
    for (int i = 0; i < step; i++) {
      prefix.push_back(wordSquare[i][step]);
    }

    for (auto &startsWithPrefix : prefixStrings[prefix]) {
      wordSquare.push_back(string(startsWithPrefix));
      backtracking(wordSquare, step + 1);
      wordSquare.pop_back();
    }
  }
};

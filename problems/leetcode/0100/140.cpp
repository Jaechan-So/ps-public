// 140. Word Break II
// https://leetcode.com/problems/word-break-ii/

using namespace std;

#include <string>
#include <vector>

class Solution {
public:
  vector<string> wordBreak(string s, vector<string> &wordDict) {
    return wordBreakImpl(s, wordDict, 0);
  }
  vector<string> wordBreakImpl(string &s, vector<string> &wordDict, int start) {
    int n = s.size();
    vector<string> answer;

    for (int i = 0; i < wordDict.size(); i++) {
      int m = wordDict[i].size();
      if (s.find(wordDict[i], start) == start) {
        if (start + m < n) {
          vector<string> rem = wordBreakImpl(s, wordDict, start + m);

          for (int j = 0; j < rem.size(); j++) {
            answer.push_back(wordDict[i] + ' ' + rem[j]);
          }
        } else {
          answer.push_back(wordDict[i]);
        }
      }
    }

    return answer;
  }
};

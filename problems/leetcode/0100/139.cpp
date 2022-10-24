// 139. Word Break
// https://leetcode.com/problems/word-break/

using namespace std;

#include <string>
#include <unordered_set>
#include <vector>

class Solution {
public:
  bool wordBreak(string s, vector<string> &wordDict) {
    unordered_set<string> dict;
    for (auto word : wordDict) {
      dict.insert(word);
    }

    vector<bool> endAvailable(s.size() + 1, false);
    endAvailable[0] = true;

    for (int i = 1; i <= s.size(); i++) {
      for (int j = i - 1; j >= 0; j--) {
        if (endAvailable[j] && dict.find(s.substr(j, i - j)) != dict.end()) {
          endAvailable[i] = true;
          break;
        }
      }
    }

    return endAvailable[s.size()];
  }
};

// 316. Remove Duplicate Letters
// https://leetcode.com/problems/remove-duplicate-letters/description/

using namespace std;

#include <string>
#include <unordered_map>
#include <unordered_set>

class Solution {
public:
  string removeDuplicateLetters(string s) {
    int n = s.size();

    unordered_set<char> appeared;
    unordered_map<char, int> lastOccurrence;
    string answer;

    for (int i = 0; i < n; i++) {
      lastOccurrence[s[i]] = i;
    }

    for (int i = 0; i < n; i++) {
      char ch = s[i];

      if (appeared.find(ch) != appeared.end()) {
        continue;
      }
      while (answer.size() > 0 && ch < answer.back() &&
             lastOccurrence[answer.back()] > i) {
        appeared.erase(answer.back());
        answer.pop_back();
      }
      appeared.insert(ch);
      answer.push_back(ch);
    }

    return answer;
  }
};

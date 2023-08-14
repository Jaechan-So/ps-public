// 767. Reorganize String
// https://leetcode.com/problems/reorganize-string/description/

using namespace std;

#include <string>
#include <utility>
#include <vector>

class Solution {
public:
  const int ALPHABET_COUNT = 'z' - 'a' + 1;

  string reorganizeString(string s) {
    vector<pair<int, char>> countAndChars;
    for (int i = 0; i < ALPHABET_COUNT; i++) {
      countAndChars.push_back({0, 'a' + i});
    }
    for (char ch : s) {
      countAndChars[ch - 'a'].first++;
    }
    sort(countAndChars.begin(), countAndChars.end(),
         [](pair<int, char> &p1, pair<int, char> &p2) -> bool {
           return p1.first > p2.first;
         });

    string newS;
    int index = 1;
    for (pair<int, char> p : countAndChars) {
      if (newS.empty()) {
        for (int i = 0; i < p.first; i++) {
          newS.push_back(p.second);
        }
        continue;
      }

      int remain = p.first;
      while (remain > 0) {
        if (newS[index - 1] != p.second &&
            (index == newS.size() || newS[index] != p.second)) {
          newS.insert(index, 1, p.second);
          remain--;
        }
        index += 2;
        if (index - 1 == newS.size()) {
          index = 1;
        }
      }
    }

    for (int i = 0; i < s.size() - 1; i++) {
      if (newS[i] == newS[i + 1]) {
        return string("");
      }
    }
    return newS;
  }
};

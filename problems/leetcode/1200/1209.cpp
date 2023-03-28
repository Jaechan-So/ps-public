// 1209. Remove All Adjacent Duplicates in String II
// https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string-ii/description/

using namespace std;

#include <string>
#include <vector>

class Solution {
public:
  string removeDuplicates(string s, int k) {
    vector<pair<char, int>> charToCounts;

    for (char ch : s) {
      if (!charToCounts.empty() && charToCounts.back().first == ch) {
        charToCounts.back().second++;
        if (charToCounts.back().second == k) {
          charToCounts.pop_back();
        }
      } else {
        charToCounts.push_back(pair<char, int>({ch, 1}));
      }
    }

    string duplicateRemovedString;
    for (pair<char, int> p : charToCounts) {
      int count = p.second;
      for (int i = 0; i < count; i++) {
        char ch = p.first;
        duplicateRemovedString.push_back(ch);
      }
    }

    return duplicateRemovedString;
  }
};

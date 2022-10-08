// 524. Longest Word in Dictionary through Deleting
// https://leetcode.com/problems/longest-word-in-dictionary-through-deleting/

using namespace std;

#include <queue>
#include <string>
#include <unordered_map>
#include <vector>

class Solution {
public:
  string findLongestWord(string s, vector<string> &dictionary) {
    // Cache each character of s with indices. For example, with s = "abpcplea",
    // a -> 0, b -> 1, p -> 2, c -> 3, p -> 4, ...
    unordered_map<char, vector<int>> sAlphabetIndicies;
    for (int i = 0; i < s.size(); i++) {
      sAlphabetIndicies[s[i]].push_back(i);
    }

    int longestWordIndex = -1;

    for (int j = 0; j < dictionary.size(); j++) {
      string &word = dictionary[j];
      int index = 0, prevIndex = -1, currIndex = 0;
      ;
      for (; index < word.size(); index++) {
        char ch = word[index];

        // If there is no alphabet in s with given character, or there are less
        // alphabet in s with given string, then abort.
        if (sAlphabetIndicies[ch].empty()) {
          break;
        }
        vector<int>::iterator iter =
            lower_bound(sAlphabetIndicies[ch].begin(),
                        sAlphabetIndicies[ch].end(), prevIndex + 1);
        if (iter == sAlphabetIndicies[ch].end()) {
          break;
        }
        currIndex = *iter;

        prevIndex = currIndex;
      }

      if (index == word.size()) {
        if (longestWordIndex == -1) {
          longestWordIndex = j;
        } else {
          if (dictionary[longestWordIndex].size() < dictionary[j].size() ||
              (dictionary[longestWordIndex].size() == dictionary[j].size()) &&
                  dictionary[j].compare(dictionary[longestWordIndex]) < 0) {
            longestWordIndex = j;
          }
        }
      }
    }

    return longestWordIndex == -1 ? string()
                                  : string(dictionary[longestWordIndex]);
  }
};

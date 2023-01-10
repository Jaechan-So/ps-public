// 1657. Determine if Two Strings Are Close
// https://leetcode.com/problems/determine-if-two-strings-are-close/description/

using namespace std;

#include <queue>
#include <string>

class Solution {
public:
  bool closeStrings(string word1, string word2) {
    if (word1.size() != word2.size()) {
      return false;
    }

    int charCount1[26] =
        {
            0,
        },
        charCount2[26] = {
            0,
        };
    for (int i = 0; i < word1.size(); i++) {
      charCount1[charToIndex(word1[i])]++;
    }
    for (int i = 0; i < word2.size(); i++) {
      charCount2[charToIndex(word2[i])]++;
    }

    priority_queue<int> pq1, pq2;
    for (int i = 0; i < 26; i++) {
      if (!isBothZeroOrBothNonZero(charCount1[i], charCount2[i])) {
        return false;
      }
      if (charCount1[i] != 0) {
        pq1.push(charCount1[i]);
      }
      if (charCount2[i] != 0) {
        pq2.push(charCount2[i]);
      }
    }

    while (!pq1.empty() && !pq2.empty()) {
      if (pq1.top() != pq2.top()) {
        return false;
      }
      pq1.pop();
      pq2.pop();
    }

    return pq1.empty() && pq2.empty();
  }

  int charToIndex(char ch) { return ch - 'a'; }

  bool isBothZeroOrBothNonZero(int n1, int n2) {
    return (n1 == 0 && n2 == 0) || (n1 != 0 && n2 != 0);
  }
};

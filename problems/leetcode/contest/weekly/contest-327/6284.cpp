// 6284. Make Number of Distinct Characters Equal
// https://leetcode.com/contest/weekly-contest-327/problems/make-number-of-distinct-characters-equal/
// Result: Accepted (with Wrong Answer 1 time)

using namespace std;

#include <string>

class Solution {
public:
  bool isItPossible(string word1, string word2) {
    int word1CharToCount[26] = {
        0,
    };
    int word2CharToCount[26] = {
        0,
    };
    for (char ch : word1) {
      word1CharToCount[charToIndex(ch)]++;
    }
    for (char ch : word2) {
      word2CharToCount[charToIndex(ch)]++;
    }

    int uniqueCharsForChar1 = 0, uniqueCharsForChar2 = 0;
    for (int i = 0; i < 26; i++) {
      if (word1CharToCount[i] != 0) {
        uniqueCharsForChar1++;
      }
      if (word2CharToCount[i] != 0) {
        uniqueCharsForChar2++;
      }
    }

    for (int i = 0; i < 26; i++) {
      if (word1CharToCount[i] == 0) {
        continue;
      }

      for (int j = 0; j < 26; j++) {
        if (word2CharToCount[j] == 0) {
          continue;
        }

        int diff1 = 0, diff2 = 0;

        if (word1CharToCount[i] == 1) {
          diff1 = i == j ? 0 : word1CharToCount[j] == 0 ? 0 : -1;
        } else {
          diff1 = word1CharToCount[j] == 0 ? 1 : 0;
        }

        if (word2CharToCount[j] == 1) {
          diff2 = i == j ? 0 : word2CharToCount[i] == 0 ? 0 : -1;
        } else {
          diff2 = word2CharToCount[i] == 0 ? 1 : 0;
        }

        if (uniqueCharsForChar1 + diff1 == uniqueCharsForChar2 + diff2) {
          return true;
        }
      }
    }

    return false;
  }

  int charToIndex(char ch) { return ch - 'a'; }

  int getAbs(int i) { return i >= 0 ? i : -i; }
};

// 1. 1개인 문자를 이미 있는 걸로(자기 자신도 포함) 바꾸기 -> -1
// 2. 1개인 문자를 없는 걸로 바꾸기 -> 0
// 3. 1개 이상인 문자를 이미 있는 걸로 바꾸기 -> 0
// 4. 1개 이상인 문자를 없는 걸로 바꾸기 -> +1

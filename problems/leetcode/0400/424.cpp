// 424. Longest Repeating Character Replacement
// https://leetcode.com/problems/longest-repeating-character-replacement/description/

using namespace std;

#include <string>

class Solution {
public:
  int characterReplacement(string s, int k) {
    int maxLength = 0;

    for (char targetChar = 'A'; targetChar <= 'Z'; targetChar++) {
      int start = 0;
      while (start < s.size() && s[start] != targetChar) {
        start++;
      }
      if (start == s.size()) {
        continue;
      }

      int nonTargetCharCount = k, end = start + 1;
      while (end < s.size()) {
        if (s[end] != targetChar) {
          if (nonTargetCharCount == 0) {
            maxLength = max(maxLength, end - start);
            while (start < s.size() && s[start] == targetChar) {
              start++;
            }
            start++;
          } else {
            nonTargetCharCount--;
          }
        }
        end++;
      }

      int possibleLength =
          (nonTargetCharCount > 0 ? min(start, nonTargetCharCount) : 0) + end -
          start;
      maxLength = max(maxLength, possibleLength);
    }

    return maxLength;
  }
};

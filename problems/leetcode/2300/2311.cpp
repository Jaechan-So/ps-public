// 2311. Longest Binary Subsequence Less Than or Equal to K
// https://leetcode.com/problems/longest-binary-subsequence-less-than-or-equal-to-k/description/

using namespace std;

#include <string>

class Solution {
public:
  int longestSubsequence(string s, int k) {
    long long exponent = 1, number = 0;
    int inverseIndex = 0, length = 0;

    while (inverseIndex < s.size()) {
      int index = s.size() - inverseIndex - 1, entry = s[index] - '0';

      if ((entry == 0) ||
          ((exponent <= LLONG_MAX / 2) && (number + (entry * exponent) <= k))) {
        number += (entry * exponent);
        if (exponent <= LLONG_MAX / 2) {
          exponent *= 2;
        }
        length++;
      }

      inverseIndex++;
    }

    return length;
  }
};

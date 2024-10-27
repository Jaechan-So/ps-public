// 32. Longest Valid Parentheses
// https://leetcode.com/problems/longest-valid-parentheses/description/

using namespace std;

#include <string>

class Solution {
public:
  int longestValidParentheses(string s) {
    int n = s.size(), maxLen = 0, left = 0, right = 0;

    for (int i = 0; i < n; i++) {
      if (s[i] == '(') {
        left++;
      } else {
        if (left == right) {
          left = 0;
          right = 0;
          continue;
        } else if (left == right + 1) {
          maxLen = max(maxLen, 2 * left);
        }
        right++;
      }
    }

    left = 0;
    right = 0;
    for (int i = n - 1; i >= 0; i--) {
      if (s[i] == ')') {
        right++;
      } else {
        if (left == right) {
          left = 0;
          right = 0;
          continue;
        } else if (right == left + 1) {
          maxLen = max(maxLen, 2 * right);
        }
        left++;
      }
    }

    return maxLen;
  }
};

// 1. ')'랑 대응되는 '(' 찾기
// 2. '(' 바로 앞 원소로 끝나는 가장 긴 길이 +. 없거나 '('이면 0

// 1. Two-pass로, 양 방향에서 검사하기

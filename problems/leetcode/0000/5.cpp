// 5. Longest Palindromic Substring
// https://leetcode.com/problems/longest-palindromic-substring/

using namespace std;

#include <string>
#include <vector>

class Solution {
public:
  int checkPalindrome(string &s, vector<vector<int>> &isPalindrome, int len,
                      int x, int y) {
    if (isPalindrome[x][y] == -1) {
      if (isPalindrome[x + 1][y - 1] == -1) {
        checkPalindrome(s, isPalindrome, len, x + 1, y - 1);
      }
      isPalindrome[x][y] =
          (isPalindrome[x + 1][y - 1] == 1) && (s[x] == s[y]) ? 1 : 0;
    }
    return isPalindrome[x][y];
  }

  string longestPalindrome(string s) {
    int len = s.size();
    vector<vector<int>> isPalindrome(len, vector<int>(len, -1));

    for (int i = 0; i < len; i++) {
      isPalindrome[i][i] = 1;
    }
    for (int i = 0; i < len - 1; i++) {
      isPalindrome[i][i + 1] = (s[i] == s[i + 1]) ? 1 : 0;
    }

    for (int i = len; i >= 2; i--) {
      for (int j = 0; j <= len - i; j++) {
        if (checkPalindrome(s, isPalindrome, len, j, i + j - 1)) {
          return s.substr(j, i);
        }
      }
    }

    return s.substr(0, 1);
  }
};

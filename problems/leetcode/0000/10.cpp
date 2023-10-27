// 10. Regular Expression Matching
// https://leetcode.com/problems/regular-expression-matching/description/

using namespace std;

#include <string>

class Solution {
public:
  bool isMatchWithIndex(vector<vector<int>> &cache, string &s, string &p,
                        int sIndex, int pIndex) {
    if (sIndex < s.size() && pIndex < p.size() && cache[sIndex][pIndex] != -1) {
      return cache[sIndex][pIndex] == 1 ? true : false;
    }

    if (sIndex == s.size() && pIndex == p.size()) {
      return true;
    }

    if (pIndex == p.size()) {
      return false;
    }

    if (pIndex < p.size() - 1 && p[pIndex + 1] == '*') {
      int nextSIndex = sIndex;

      while (nextSIndex < s.size() &&
             (p[pIndex] == '.' || s[nextSIndex] == p[pIndex])) {
        if (isMatchWithIndex(cache, s, p, nextSIndex, pIndex + 2)) {
          cache[sIndex][pIndex] = 1;
          return true;
        }
        nextSIndex++;
      }

      bool result = isMatchWithIndex(cache, s, p, nextSIndex, pIndex + 2);
      if (sIndex < s.size() && pIndex < p.size()) {
        cache[sIndex][pIndex] = result ? 1 : 0;
      }
      return result;
    }

    if (sIndex == s.size()) {
      return false;
    }

    if (p[pIndex] == '.') {
      bool result = isMatchWithIndex(cache, s, p, sIndex + 1, pIndex + 1);
      cache[sIndex][pIndex] = result ? 1 : 0;
      return result;
    }

    bool result = s[sIndex] == p[pIndex] &&
                  isMatchWithIndex(cache, s, p, sIndex + 1, pIndex + 1);
    cache[sIndex][pIndex] = result ? 1 : 0;
    return result;
  }

  bool isMatch(string s, string p) {
    int m = s.size(), n = p.size();
    vector<vector<int>> cache(m, vector<int>(n, -1));

    return isMatchWithIndex(cache, s, p, 0, 0);
  }
};

// 1. Naive, Backtracking
// s의 위치를 하나씩 옮기면서 p에 있는 문자를 순차적으로 확인한다.
// i. (문자 + *)인 경우, 현재 s의 위치에 있는 문자가 p에 있는 문자인지 확인.
// ii. 단순히 문자인 경우, 두 문자를 비교.
// iii. .인 경우, 바로 넘어감.

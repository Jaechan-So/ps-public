// 2272. Substring With Largest Variance
// https://leetcode.com/problems/substring-with-largest-variance/description/

using namespace std;

#include <string>

class Solution {
public:
  int largestVariance(string s) {
    int var = 0;

    int count[26] = {
        0,
    };
    for (char ch : s) {
      count[ch - 'a']++;
    }

    for (char major = 'a'; major <= 'z'; major++) {
      for (char minor = 'a'; minor <= 'z'; minor++) {
        if (major == minor || count[major - 'a'] == 0 ||
            count[minor - 'a'] == 0) {
          continue;
        }

        int majorCount = 0, minorCount = 0, restMinorCount = count[minor - 'a'];
        for (char ch : s) {
          if (ch == major) {
            majorCount++;
          }
          if (ch == minor) {
            minorCount++;
            restMinorCount--;
          }

          if (minorCount > 0) {
            var = max(var, majorCount - minorCount);
          }

          if (majorCount < minorCount && restMinorCount > 0) {
            majorCount = 0;
            minorCount = 0;
          }
        }
      }
    }

    return var;
  }
};

// 1. Naive
// O(n^2)으로 모두 찾아본다. 시작 위치를 고정하면, O(n) Map을 이용해서 관리할 수
// 있다.

// 2. Two Pointer + Greedy -> 반례: aabaaaabbabbb

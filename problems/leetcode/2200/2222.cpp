// 2222. Number of Ways to Select Buildings
// https://leetcode.com/problems/number-of-ways-to-select-buildings/description

using namespace std;

#include <string>
#include <vector>

class Solution {
public:
  long long numberOfWays(string s) {
    vector<long long> counts(6, 0); // 0, 1, 01, 10, 010, 101

    for (char ch : s) {
      if (ch == '0') {
        counts[0] += 1;
        counts[3] += counts[1];
        counts[4] += counts[2];
      } else {
        counts[1] += 1;
        counts[2] += counts[0];
        counts[5] += counts[3];
      }
    }

    return counts[4] + counts[5];
  }
};

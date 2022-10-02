// 115. Distinct Subsequences
// https://leetcode.com/problems/distinct-subsequences/

using namespace std;

#include <string>

class Solution {
public:
  int dp[1001][1001];
  int numDistinct(string s, string t) {
    for (int i = 0; i <= s.size(); i++) {
      for (int j = 0; j <= t.size(); j++) {
        dp[i][j] = -1;
      }
    }
    for (int i = 0; i <= t.size(); i++) {
      dp[0][i] = 0;
    }
    for (int i = 0; i <= s.size(); i++) {
      dp[i][0] = 1;
    }

    return dfs(s, t, s.size(), t.size());
  }

  int dfs(string &s, string &t, int sIndex, int tIndex) {
    if (dp[sIndex][tIndex] != -1) {
      return dp[sIndex][tIndex];
    }

    if (sIndex < tIndex) {
      dp[sIndex][tIndex] = 0;
      return dp[sIndex][tIndex];
    }

    if (s[sIndex - 1] == t[tIndex - 1]) {
      dp[sIndex][tIndex] =
          dfs(s, t, sIndex - 1, tIndex - 1) + dfs(s, t, sIndex - 1, tIndex);
    } else {
      dp[sIndex][tIndex] = dfs(s, t, sIndex - 1, tIndex);
    }

    return dp[sIndex][tIndex];
  }
};

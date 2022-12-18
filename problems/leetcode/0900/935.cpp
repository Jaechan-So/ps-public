// 935. Knight Dialer
// https://leetcode.com/problems/knight-dialer/description/

class Solution {
public:
  int knightDialer(int n) {
    long long dp[5001][10];

    for (int i = 0; i < 10; i++) {
      dp[1][i] = 1;
    }

    for (int i = 2; i <= n; i++) {
      dp[i][0] = getModulo(dp[i - 1][4] + dp[i - 1][6]);
      dp[i][1] = getModulo(dp[i - 1][6] + dp[i - 1][8]);
      dp[i][2] = getModulo(dp[i - 1][7] + dp[i - 1][9]);
      dp[i][3] = getModulo(dp[i - 1][4] + dp[i - 1][8]);
      dp[i][4] = getModulo(dp[i - 1][3] + dp[i - 1][9] + dp[i - 1][0]);
      dp[i][5] = 0;
      dp[i][6] = getModulo(dp[i - 1][1] + dp[i - 1][7] + dp[i - 1][0]);
      dp[i][7] = getModulo(dp[i - 1][2] + dp[i - 1][6]);
      dp[i][8] = getModulo(dp[i - 1][1] + dp[i - 1][3]);
      dp[i][9] = getModulo(dp[i - 1][2] + dp[i - 1][4]);
    }

    int answer = 0;
    for (int i = 0; i < 10; i++) {
      answer = getModulo(answer + dp[n][i]);
    }

    return answer;
  }

  long long getModulo(long long ll) { return ll % 1000000007; }
};

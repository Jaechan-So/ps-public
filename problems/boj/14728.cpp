#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>

using namespace std;

int n, t;
int dp[101][10001];
int chapters[101][2];

void solve(int i, int j) {
  if (j < chapters[i][0]) {
    dp[i][j] = dp[i - 1][j];
  } else {
    dp[i][j] =
        max(dp[i - 1][j], dp[i - 1][j - chapters[i][0]] + chapters[i][1]);
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> t;
  for (int i = 1; i <= n; i++) {
    int k, s;
    cin >> k >> s;
    chapters[i][0] = k;
    chapters[i][1] = s;
  }

  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= t; j++) {
      dp[i][j] = 0;
    }
  }

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= t; j++) {
      solve(i, j);
    }
  }

  cout << dp[n][t] << '\n';
  return 0;
}

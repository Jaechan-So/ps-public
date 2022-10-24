#include <iostream>

using namespace std;

int _map[501][501];
int dp[501][501];
int m, n;

void pathFind(int x, int y) {
  if (dp[x][y] != -1) {
    return;
  }
  dp[x][y] = 0;
  if (x - 1 >= 1 && _map[x][y] < _map[x - 1][y]) {
    pathFind(x - 1, y);
    dp[x][y] += dp[x - 1][y];
  }
  if (y - 1 >= 1 && _map[x][y] < _map[x][y - 1]) {
    pathFind(x, y - 1);
    dp[x][y] += dp[x][y - 1];
  }
  if (x + 1 <= m && _map[x][y] < _map[x + 1][y]) {
    pathFind(x + 1, y);
    dp[x][y] += dp[x + 1][y];
  }
  if (y + 1 <= n && _map[x][y] < _map[x][y + 1]) {
    pathFind(x, y + 1);
    dp[x][y] += dp[x][y + 1];
  }
}

int main() {
  cin >> m >> n;
  for (int i = 1; i <= m; i++) {
    for (int j = 1; j <= n; j++) {
      int height;
      cin >> height;
      _map[i][j] = height;
    }
  }

  for (int i = 1; i <= m; i++) {
    for (int j = 1; j <= n; j++) {
      dp[i][j] = -1;
    }
  }
  dp[1][1] = 1;

  int x = m, y = n;
  pathFind(x, y);

  cout << dp[x][y] << '\n';
  return 0;
}

#include <bits/stdc++.h>

using namespace std;

int n;
int inputs[501][2];
int path[501][501];

void dp(int x, int y) {
  if (x == y) {
    path[x][y] = 0;
    return;
  } else {
    if (path[x][y] != -1) {
      return;
    } else {
      for (int k = x; k < y; k++) {
        dp(x, k);
        dp(k + 1, y);
        if (path[x][y] == -1) {
          path[x][y] = path[x][k] + path[k + 1][y] +
                       (inputs[x][0] * inputs[k][1] * inputs[y][1]);
        } else {
          path[x][y] =
              min(path[x][y], path[x][k] + path[k + 1][y] +
                                  (inputs[x][0] * inputs[k][1] * inputs[y][1]));
        }
      }
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  for (int i = 1; i <= n; i++) {
    int r, c;
    cin >> r >> c;
    inputs[i][0] = r;
    inputs[i][1] = c;
  }

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      path[i][j] = -1;
    }
  }

  dp(1, n);
  cout << path[1][n] << '\n';

  return 0;
}

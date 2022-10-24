#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

class DP {
public:
  int length;
  int dir; // 0: upper-left, 1: left, 2: up, 3: None
  DP();
  DP(int _length, int _dir);
};

DP::DP() {
  length = 0;
  dir = 3;
}

DP::DP(int _length, int _dir) {
  length = _length;
  dir = _dir;
}

int main() {
  string a, b;
  cin >> a >> b;
  int len_a, len_b;
  len_a = a.length();
  len_b = b.length();
  DP dp[len_a + 1][len_b + 1];

  DP init_elem = DP(0, 3);
  dp[0][0] = init_elem;

  for (int i = 1; i < len_a + 1; i++) {
    DP elem = DP(0, 3);
    dp[i][0] = elem;
  }

  for (int i = 1; i < len_b + 1; i++) {
    DP elem = DP(0, 3);
    dp[0][i] = elem;
  }

  for (int i = 1; i < len_a + 1; i++) {
    for (int j = 1; j < len_b + 1; j++) {
      // index: i-1 and j-1 for string
      if (a[i - 1] == b[j - 1]) {
        DP elem = DP(dp[i - 1][j - 1].length + 1, 0);
        dp[i][j] = elem;
      } else {
        if (dp[i - 1][j].length > dp[i][j - 1].length) {
          DP elem = DP(dp[i - 1][j].length, 2);
          dp[i][j] = elem;
        } else {
          DP elem = DP(dp[i][j - 1].length, 1);
          dp[i][j] = elem;
        }
      }
    }
  }

  cout << dp[len_a][len_b].length << '\n';
  return 0;
}

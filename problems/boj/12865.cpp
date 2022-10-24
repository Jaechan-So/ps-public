#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Good {
public:
  int weight;
  int value;
  Good(int _weight, int _value);
};

Good::Good(int _weight, int _value) {
  weight = _weight;
  value = _value;
}

int main() {
  int n, k;
  cin >> n >> k;
  vector<Good> goods;
  for (int i = 0; i < n; i++) {
    int w, v;
    cin >> w >> v;
    goods.push_back(Good(w, v));
  }

  int dp[n + 1][k + 1];
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= k; j++) {
      dp[i][j] = 0;
    }
  }

  for (int i = 1; i <= k; i++) {
    for (int j = 1; j <= n; j++) {
      if (goods[j - 1].weight > i) {
        dp[j][i] = dp[j - 1][i];
      } else {
        dp[j][i] = max(dp[j - 1][i - goods[j - 1].weight] + goods[j - 1].value,
                       dp[j - 1][i]);
      }
    }
  }

  cout << dp[n][k] << '\n';
  return 0;
}

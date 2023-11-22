// 1420. Build Array Where You Can Find The Maximum Exactly K Comparisons
// https://leetcode.com/problems/build-array-where-you-can-find-the-maximum-exactly-k-comparisons/description/

using namespace std;

#include <vector>

class Solution {
public:
  const int mod = 1e9 + 7;

  int numOfArrays(int n, int m, int k) {
    if (k == 0) {
      return 0;
    }

    vector<vector<long long>> dp(m + 1, vector<long long>(k + 1, 0));
    for (int q = 0; q <= m; q++) {
      dp[q][0] = 1;
    }

    for (int p = n - 1; p >= 0; p--) {
      vector<vector<long long>> newDp(m + 1, vector<long long>(k + 1, 0));

      for (int q = m; q >= 0; q--) {
        for (int r = 0; r <= k; r++) {
          long long cases = (q * dp[q][r]) % mod;
          if (r >= 1) {
            for (int x = m; x >= q + 1; x--) {
              cases += dp[x][r - 1];
              cases %= mod;
            }
          }
          newDp[q][r] = cases;
        }
      }

      dp = newDp;
    }

    return dp[0][k];
  }
};

// [1, m]을 [1, x]와 [x, m] 2개의 범위로 쪼갠다.
// 이렇게 쪼갰을 때 [x, m] 범위에서 k개의 수를 고르고(중복 X)
// 이 때 k개의 수가 차지하는 자리는 고정적으로 맨 첫 자리를 차지하고, 나머지
// 자리를 고를 수 있다. k개의 수 사이 위치의 나머지 각 숫자가 점유할 수 있는
// 범위는, [1, k_i]이다. 이 때 k_i는 왼쪽으로 가장 가까이 있는 k개 수 집합에
// 속하는 수이다.

// DP?
// Base case: n = 1, m = 1, k = 0 -> 0. k == 0이면 0이다. (불가능)
// Base case: n == k -> n개의 숫자 모두가 Monotonically Increasing이면 된다. 즉,
// m C n. m < n인 경우 0. n = 2, m = 3, k = 1 -> k == 1인 경우, 첫 자리를 먼저
// 고르고, 나머지 뒷 자리들은 그것보다 작거나 같은 값들을 아무렇게나 선택하면
// 된다. 따라서, sigma_(x = 1 to m)(x ^ (n - 1)) n = 3, m = 4, k = 2 -> k == 2인
// 경우, dp[n][m][k] -> dp[n - 1][m][k - 1]

// [Solution]
// dp[p][q][r]: 원소를 p개 만큼 채운 상황이고, 그 안의 최댓값이 q, 남은 peek의
// 개수가 r일 때 가능한 경우의 수 목표: dp[0][0][k] 구하기 Base case: dp[p ==
// n][q][r] = (r == 0 ? 1 : 0) dp[p][q][r] = (q * dp[p + 1][q][r]) + sigma_(x =
// q + 1 to m)(dp[p + 1][x][r - 1])

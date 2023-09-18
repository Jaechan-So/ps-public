// 1074. Number of Submatrices That Sum to Target
// https://leetcode.com/problems/number-of-submatrices-that-sum-to-target/description/

using namespace std;

#include <map>
#include <vector>

class Solution {
public:
  int numSubmatrixSumTarget(vector<vector<int>> &matrix, int target) {
    int m = matrix.size(), n = matrix[0].size();

    vector<vector<long long>> prefixSum(m + 1, vector<long long>(n + 1, 0));
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        prefixSum[i + 1][j + 1] = prefixSum[i + 1][j] + prefixSum[i][j + 1] -
                                  prefixSum[i][j] + matrix[i][j];
      }
    }

    int count = 0;

    for (int r1 = 0; r1 < m; r1++) {
      for (int r2 = r1; r2 < m; r2++) {
        unordered_map<long long, int> sumToCount;
        sumToCount[0] = 1;

        for (int c = 0; c < n; c++) {
          long long sum = (prefixSum[r2 + 1][c + 1] - prefixSum[r1][c + 1]);
          count += sumToCount[sum - target];
          sumToCount[sum]++;
        }
      }
    }

    return count;
  }
};

// 1. Naive
// Brute Force로 모두 직접 시도한다.

// 2. 2차원 Prefix Sum
// Prefix Sum을 구해두면 지정한 범위의 합을 O(1)으로 구할 수 있음.
// 그러나, 범위를 구하는 경우의 수가 (m^2) * (n^2) 이므로 이 값이 10^8 정도
// 되어서 TLE가 예상됨.

// 3. [정답 풀이] 2차원 Prefix Sum + 범위 고정하기

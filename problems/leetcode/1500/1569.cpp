// 1569. Number of Ways to Reorder Array to Get Same BST
// https://leetcode.com/problems/number-of-ways-to-reorder-array-to-get-same-bst/description/

using namespace std;

#include <vector>

class Solution {
public:
  const int mod = 1e9 + 7;

  vector<vector<long long>> getCombinations(int n) {
    vector<vector<long long>> combinations(n + 1, vector<long long>(n + 1, 1));

    for (int i = 2; i <= n; i++) {
      for (int j = 1; j < i; j++) {
        combinations[i][j] =
            (combinations[i - 1][j] + combinations[i - 1][j - 1]) % mod;
      }
    }

    return combinations;
  }

  int numOfWaysInner(vector<int> &nums,
                     vector<vector<long long>> &combinations) {
    if (nums.size() < 3) {
      return 1;
    }

    vector<int> smaller, bigger;
    for (int i = 1; i < nums.size(); i++) {
      if (nums[i] < nums[0]) {
        smaller.push_back(nums[i]);
      } else {
        bigger.push_back(nums[i]);
      }
    }

    int smallerLength = smaller.size(),
        smallerResult = numOfWaysInner(smaller, combinations),
        biggerLength = bigger.size(),
        biggerResult = numOfWaysInner(bigger, combinations);
    long long numOfOrders =
        combinations[smallerLength + biggerLength][smallerLength];

    return (int)((((numOfOrders * smallerResult) % mod) * biggerResult) % mod);
  }

  int numOfWays(vector<int> &nums) {
    vector<vector<long long>> combinations = getCombinations(nums.size());
    return (int)((numOfWaysInner(nums, combinations) - 1) % mod);
  }
};

// 1. 1번째 원소는 고정, 그 원소보다 각각 크고 작은 첫 번째 원소의 위치를 먼저
// 파악해야 한다.
// 2. 각 위치를 기준으로, 이를 반복해야 한다. 양 쪽에서 가능한 경우의 수를
// 구해서 반환한다.
// 3. 각각의 원소의 개수를 m, n이라고 할 때, (m+n)Cm 가지수의 섞는 경우의 수가
// 일단 존재하고, 그 내부의 경우의 수를 각각 곱해주면 될 것 같다.

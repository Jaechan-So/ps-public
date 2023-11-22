// 1425. Constrained Subsequence Sum
// https://leetcode.com/problems/constrained-subsequence-sum/description/

using namespace std;

#include <map>
#include <vector>

class Solution {
public:
  int constrainedSubsetSum(vector<int> &nums, int k) {
    int n = nums.size(), sum = INT_MIN;
    vector<int> sums(nums);
    map<int, int> count;

    for (int i = 0; i < n; i++) {
      if (!count.empty()) {
        sums[i] = max(sums[i], count.rbegin()->first + nums[i]);
      }

      count[sums[i]]++;
      if (i - k >= 0) {
        count[sums[i - k]]--;
        if (count[sums[i - k]] == 0) {
          count.erase(sums[i - k]);
        }
      }
    }

    return *max_element(sums.begin(), sums.end());
  }
};

// 1. Naive
// O(n * (2 ^ n))

// 2. DP?
// dp[i]: 규칙을 만족하면서, 1부터 i까지 고려한 합
// dp[i] = max(max_(j = max(0, j - k) to i - 1)(dp[j]) + nums[i], nums[i])
// [10, 12, 2, 17, 37]
// [-1, -2, -3]
// [10, 8, 0, 3, 23]

// 3. DP 개선
// C++의 map 자료구조는 R-B Tree 기반 BST이므로, Sorted Tree 구조임
// 따라서 이를 이용해서, 크기가 k인 Window의 최댓값을 계속 유지할 수 있음.

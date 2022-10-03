// 198. House Robber
// https://leetcode.com/problems/house-robber/

using namespace std;

#include <vector>

class Solution {
public:
  int rob(vector<int> &nums) {
    int n = nums.size();
    if (n == 1) {
      return nums[0];
    }

    vector<int> cumulative_answers(n, 0);
    cumulative_answers[0] = nums[0];
    cumulative_answers[1] = max(nums[1], nums[0]);
    for (int i = 2; i < n; i++) {
      cumulative_answers[i] =
          max(cumulative_answers[i - 2] + nums[i], cumulative_answers[i - 1]);
    }

    return cumulative_answers[n - 1];
  }
};

// 377. Combination Sum IV
// https://leetcode.com/problems/combination-sum-iv/description/

using namespace std;

#include <unordered_map>
#include <vector>

class Solution {
public:
  unordered_map<int, int> memo;

  int combinationSum4(vector<int> &nums, int target) {
    if (target == 0) {
      return 1;
    }

    if (memo.find(target) != memo.end()) {
      return memo[target];
    }

    memo[target] = 0;
    for (int num : nums) {
      if (target - num >= 0) {
        memo[target] += combinationSum4(nums, target - num);
      }
    }

    return memo[target];
  }
};

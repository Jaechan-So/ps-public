// 416. Partition Equal Subset Sum
// https://leetcode.com/problems/partition-equal-subset-sum/description/

using namespace std;

#include <map>
#include <numeric>
#include <vector>

class Solution {
public:
  bool dfs(vector<int> &nums, int i, int current, int target,
           map<pair<int, int>, bool> &memo) {
    if (memo.find({i, current}) != memo.end()) {
      return memo[{i, current}];
    }

    if (current > target) {
      return false;
    }

    if (i == nums.size()) {
      return current == target;
    }

    bool available = dfs(nums, i + 1, current + nums[i], target, memo) ||
                     dfs(nums, i + 1, current, target, memo);
    memo[{i, current}] = available;
    return available;
  }

  bool canPartition(vector<int> &nums) {
    int total = accumulate(nums.begin(), nums.end(), 0);
    if (total % 2 != 0) {
      return false;
    }
    int target = total / 2;

    // (index, sum)
    map<pair<int, int>, bool> memo;
    return dfs(nums, 0, 0, target, memo);
  }
};

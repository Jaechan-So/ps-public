// 494. Target Sum
// https://leetcode.com/problems/target-sum/description/

using namespace std;

#include <vector>

class Solution {
public:
  int findTargetSumWays(vector<int> &nums, int target) {
    return getWays(nums, target, 0, 0);
  }

  int getWays(vector<int> &nums, int target, int position, int currentSum) {
    if (position == nums.size()) {
      return currentSum == target ? 1 : 0;
    }

    return getWays(nums, target, position + 1, currentSum + nums[position]) +
           getWays(nums, target, position + 1, currentSum - nums[position]);
  }
};

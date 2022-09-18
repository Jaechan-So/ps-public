// 665. Non-decreasing Array
// https://leetcode.com/problems/non-decreasing-array/

using namespace std;

#include <vector>

class Solution {
public:
  bool checkPossibility(vector<int> &nums) {
    if (nums.size() < 3) {
      return true;
    }

    bool usedModifyChance = nums[0] > nums[1];
    if (nums[0] > nums[1]) {
      nums[0] = nums[1];
    }

    for (int i = 0; i < nums.size() - 2; i++) {
      if (nums[i] <= nums[i + 1] && nums[i + 1] <= nums[i + 2]) {
        continue;
      }

      if (nums[i] > nums[i + 1] && nums[i + 1] > nums[i + 2]) {
        return false;
      }

      if (usedModifyChance) {
        return false;
      }

      usedModifyChance = true;
      if (i < nums.size() - 3) {
        if (nums[i] <= nums[i + 2] && nums[i + 2] < nums[i + 1]) {
          nums[i + 1] = nums[i];
        } else if (nums[i + 2] <= nums[i] && nums[i] <= nums[i + 1]) {
          nums[i + 2] = nums[i + 1];
        }
      }
    }

    return true;
  }
};

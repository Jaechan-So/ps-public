// 137. Single Number II
// https://leetcode.com/problems/single-number-ii/

using namespace std;

#include <vector>

class Solution {
public:
  int singleNumber(vector<int> &nums) {
    sort(nums.begin(), nums.end());

    for (int i = 0; i < nums.size() - 1; i += 3) {
      if (nums[i] != nums[i + 1]) {
        return nums[i];
      }
    }

    return nums[nums.size() - 1];
  }
};

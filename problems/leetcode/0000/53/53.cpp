// 53. Maximum Subarray
// https://leetcode.com/problems/maximum-subarray/

using namespace std;

#include <vector>

class Solution {
public:
  int maxSubArray(vector<int> &nums) {
    int r = nums[0];

    for (int i = 1, imax = r; i < nums.size(); i++) {
      imax = max(nums[i], imax + nums[i]);
      r = max(r, imax);
    }

    return r;
  }
};

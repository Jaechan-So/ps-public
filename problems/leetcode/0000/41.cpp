// 41. First Missing Positive
// https://leetcode.com/problems/first-missing-positive/

using namespace std;

#include <vector>

class Solution {
public:
  int firstMissingPositive(vector<int> &nums) {
    sort(nums.begin(), nums.end());

    int lastPositiveNum = 0;
    for (int i = 0; i < nums.size(); i++) {
      if (nums[i] > 0 && lastPositiveNum + 1 < nums[i]) {
        break;
      } else if (nums[i] > 0) {
        lastPositiveNum = nums[i];
      }
    }

    return lastPositiveNum + 1;
  }
};

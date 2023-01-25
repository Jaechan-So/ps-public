// 75. Sort Colors
// https://leetcode.com/problems/sort-colors/description/

using namespace std;

#include <vector>

class Solution {
public:
  void sortColors(vector<int> &nums) {
    int indicies[3] = {
        0,
    };

    for (int i = 0; i < nums.size(); i++) {
      int color = nums[i];

      swap(nums[indicies[color]], nums[i]);
      if (nums[i] == 1) {
        swap(nums[indicies[1]], nums[i]);
      }

      for (int j = color; j <= 2; j++) {
        indicies[j]++;
      }
    }
  }
};

// 16. 3Sum Closest
// https://leetcode.com/problems/3sum-closest/description/

using namespace std;

#include <algorithm>
#include <vector>

class Solution {
public:
  int threeSumClosest(vector<int> &nums, int target) {
    int n = nums.size(), closest = nums[0] + nums[1] + nums[2];
    sort(nums.begin(), nums.end());

    for (int i = 0; i < n; i++) {
      int start = i + 1, end = n - 1;

      while (start < end) {
        int sum = nums[i] + nums[start] + nums[end];
        if (abs(target - sum) < abs(target - closest)) {
          closest = sum;
        }

        if (sum < target) {
          start++;
        } else if (sum > target) {
          end--;
        } else {
          return sum;
        }
      }
    }

    return closest;
  }
};

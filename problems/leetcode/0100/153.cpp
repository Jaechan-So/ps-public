// 153. Find Minimum in Rotated Sorted Array
// https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/description/

using namespace std;

#include <vector>

class Solution {
public:
  int findMin(vector<int> &nums) {
    int start = 0, end = nums.size() - 1;

    if (nums[start] < nums[end]) {
      return nums[start];
    }

    while (start + 1 < end) {
      int first = (2 * start + end) / 3, second = (start + 2 * end) / 3;

      if (nums[first] > nums[second]) {
        start = first;
        end = second;
      } else if (nums[first] < nums[second]) {
        if (nums[start] > nums[first]) {
          end = first;
        } else if (nums[second] > nums[end]) {
          start = second;
        }
      }
    }

    return start == nums.size() - 1 ? nums[start]
                                    : min(nums[start], nums[start + 1]);
  }
};

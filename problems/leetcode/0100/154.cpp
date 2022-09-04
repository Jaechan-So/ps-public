// 154. Find Minimum in Rotated Sorted Array II
// https://leetcode.com/problems/find-minimum-in-rotated-sorted-array-ii/

using namespace std;

#include <vector>

class Solution {
public:
  int findMin(vector<int> &nums) {
    int start = 0, end = nums.size() - 1;

    while (start < end) {
      int mid = start + (end - start) / 2;

      if (nums[mid] < nums[end]) {
        end = mid;
      } else if (nums[mid] > nums[end]) {
        start = mid + 1;
      } else {
        end -= 1;
      }
    }

    return nums[start];
  }
};

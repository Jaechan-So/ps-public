// 33. Search in Rotated Sorted Array
// https://leetcode.com/problems/search-in-rotated-sorted-array/description/

using namespace std;

#include <vector>

class Solution {
public:
  int search(vector<int> &nums, int target) {
    int n = nums.size(), start = 0, end = n - 1;

    while (start <= end) {
      int mid = (start + end) / 2;

      if (nums[mid] == target) {
        return mid;
      }

      if (nums[start] <= nums[mid]) {
        // Left is monotonically increasing, Right is rotated
        if (nums[start] <= target && target < nums[mid]) {
          end = mid - 1;
        } else {
          start = mid + 1;
        }
      } else {
        // Left is rotated, Right is monotonically increasing
        if (nums[mid] < target && target <= nums[end]) {
          start = mid + 1;
        } else {
          end = mid - 1;
        }
      }
    }

    return -1;
  }
};

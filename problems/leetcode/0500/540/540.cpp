// 540. Single Element in a Sorted Array
// https://leetcode.com/problems/single-element-in-a-sorted-array/

using namespace std;

#include <vector>

class Solution {
public:
  int singleNonDuplicate(vector<int> &nums) {
    // Use binary search, holding range with odd size.
    int start = 0, end = nums.size() - 1;

    if (start == end) {
      return nums[0];
    }

    while (end - start > 2) {
      int mid = (start + end) / 2, splitSize = (end - start) / 2;

      // odd split size -> different side
      // even split size -> same side
      if (nums[mid - 1] != nums[mid] && nums[mid] != nums[mid + 1]) {
        return nums[mid];
      }

      if ((splitSize % 2 == 1 && nums[mid] == nums[mid + 1]) ||
          (splitSize % 2 == 0 && nums[mid - 1] == nums[mid])) {
        end = mid - (1 + (splitSize % 2 == 0 ? 1 : 0));
      } else {
        start = mid + (1 + (splitSize % 2 == 0 ? 1 : 0));
      }
    }

    return nums[start] == nums[start + 1]       ? nums[start + 2]
           : nums[start + 1] == nums[start + 2] ? nums[start]
                                                : nums[start + 1];
  }
};

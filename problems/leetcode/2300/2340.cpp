// 2340. Minimum Adjacent Swaps to Make a Valid Array
// https://leetcode.com/problems/minimum-adjacent-swaps-to-make-a-valid-array/description

using namespace std;

#include <utility>
#include <vector>

class Solution {
public:
  int minimumSwaps(vector<int> &nums) {
    int n = nums.size();

    int minNum = INT_MAX, maxNum = INT_MIN;
    for (int num : nums) {
      minNum = min(minNum, num);
      maxNum = max(maxNum, num);
    }

    int minIndex = -1, maxIndex = -1;
    for (int i = 0; i < n; i++) {
      if (minIndex == -1 && nums[i] == minNum) {
        minIndex = i;
      }
    }
    for (int i = n - 1; i >= 0; i--) {
      if (maxIndex == -1 && nums[i] == maxNum) {
        maxIndex = i;
      }
    }

    return minIndex + (n - 1 - maxIndex) - (minIndex > maxIndex ? 1 : 0);
  }
};

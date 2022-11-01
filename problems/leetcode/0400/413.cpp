// 413. Arithmetic Slices
// https://leetcode.com/problems/arithmetic-slices/

using namespace std;

#include <vector>

class Solution {
public:
  int numberOfArithmeticSlices(vector<int> &nums) {
    if (nums.size() < 3) {
      return 0;
    }

    int answer = 0, continuousNums = -1, difference = nums[1] - nums[0];

    for (int i = 0; i < nums.size() - 1; i++) {
      if (nums[i + 1] - nums[i] == difference) {
        continuousNums++;

        if (continuousNums >= 1) {
          answer += continuousNums;
        }
      } else {
        continuousNums = 0;
      }

      difference = nums[i + 1] - nums[i];
    }

    return answer;
  }
};

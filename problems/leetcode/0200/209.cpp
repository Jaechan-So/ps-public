// 209. Minimum Size Subarray Sum
// https://leetcode.com/problems/minimum-size-subarray-sum/

using namespace std;

#include <vector>

class Solution {
public:
  int minSubArrayLen(int target, vector<int> &nums) {
    int answer = INT_MAX;

    int slow = 0, fast = 0, currentSum = 0;
    while (fast < nums.size()) {
      if (currentSum < target) {
        currentSum += nums[fast];
        fast++;
      } else {
        answer = min(answer, fast - slow);
        currentSum -= nums[slow];
        slow++;
        if (slow > fast) {
          currentSum += nums[fast];
          fast++;
        }
      }
    }
    while (slow < nums.size() && currentSum >= target) {
      answer = min(answer, (int)nums.size() - slow);
      currentSum -= nums[slow];
      slow++;
    }

    return answer == INT_MAX ? 0 : answer;
  }
};

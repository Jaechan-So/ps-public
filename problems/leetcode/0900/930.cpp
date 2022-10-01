// 930. Binary Subarrays With Sum
// https://leetcode.com/problems/binary-subarrays-with-sum/

using namespace std;

#include <vector>

class Solution {
public:
  int numSubarraysWithSum(vector<int> &nums, int goal) {
    int slow = -1, fast = -1;
    long long answer = 0;

    if (goal == 0) {
      long long continuousZeros = 0;

      for (int i = 0; i < nums.size(); i++) {
        if (nums[i] == 0) {
          continuousZeros++;
        } else if (continuousZeros != 0 && nums[i] != 0) {
          answer += (continuousZeros * (continuousZeros + 1)) / 2;
          continuousZeros = 0;
        }
      }

      answer += (continuousZeros * (continuousZeros + 1)) / 2;
      return answer;
    }

    int current = 0;
    for (int i = 0; i < nums.size(); i++) {
      if (nums[i] == 1) {
        current++;
        if (slow == -1) {
          slow = i;
        }
      }
      if (current == goal) {
        fast = i;
        break;
      }
    }
    if (slow == -1) {
      slow = 0;
    }

    int prevSlow = -1;
    while (fast < nums.size()) {
      int nextFast = fast + 1;
      while (nextFast < nums.size() && nums[nextFast] == 0) {
        nextFast++;
      }
      answer += (slow - prevSlow) * (nextFast - fast);
      fast = nextFast;
      prevSlow = slow;
      slow++;
      while (slow < fast && nums[slow] == 0) {
        slow++;
      }
    }

    return answer;
  }
};

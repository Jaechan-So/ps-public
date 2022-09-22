// 1438. Longest Continuous Subarray With Absolute Diff Less Than or Equal to
// Limit
// https://leetcode.com/problems/longest-continuous-subarray-with-absolute-diff-less-than-or-equal-to-limit/

using namespace std;

#include <set>
#include <vector>

class Solution {
public:
  int longestSubarray(vector<int> &nums, int limit) {
    if (nums.size() == 1) {
      return 1;
    }

    multiset<int> numSet;

    int slow = 0, fast = 0, answer = 1;
    numSet.insert(nums[0]);

    while (fast < nums.size()) {
      if ((*numSet.rbegin() - *numSet.begin()) <= limit) {
        answer = max(answer, (int)numSet.size());
        fast++;
        if (fast < nums.size()) {
          numSet.insert(nums[fast]);
        }
      } else {
        numSet.erase(numSet.find(nums[slow++]));
      }
    }

    while (slow < nums.size()) {
      if ((*numSet.rbegin() - *numSet.begin()) <= limit) {
        answer = max(answer, (int)numSet.size());
      }
      numSet.erase(numSet.find(nums[slow++]));
    }

    return answer;
  }
};

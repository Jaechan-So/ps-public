// 2869. Minimum Operations to Collect Elements
// https://leetcode.com/contest/biweekly-contest-114/problems/minimum-operations-to-collect-elements/
// Result: Accepted

using namespace std;

#include <unordered_set>
#include <vector>

class Solution {
public:
  int minOperations(vector<int> &nums, int k) {
    unordered_set<int> occur;

    for (int i = (int)nums.size() - 1; i >= 0; i--) {
      int num = nums[i];
      if (num <= k) {
        occur.insert(num);
      }
      if (occur.size() == k) {
        return nums.size() - i;
      }
    }

    return 1;
  }
};

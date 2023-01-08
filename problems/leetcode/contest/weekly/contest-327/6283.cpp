// 6283. Maximum Count of Positive Integer and Negative Integer
// https://leetcode.com/contest/weekly-contest-327/problems/maximum-count-of-positive-integer-and-negative-integer/
// Result: Accepted

using namespace std;

#include <vector>

class Solution {
public:
  int maximumCount(vector<int> &nums) {
    int zeroIndex = lower_bound(nums.begin(), nums.end(), 0) - nums.begin();
    int positiveIndex = lower_bound(nums.begin(), nums.end(), 1) - nums.begin();
    return max(zeroIndex, (int)nums.size() - positiveIndex);
  }
};

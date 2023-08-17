// 2461. Maximum Sum of Distinct Subarrays With Length K
// https://leetcode.com/problems/maximum-sum-of-distinct-subarrays-with-length-k/description

using namespace std;

#include <map>
#include <utility>
#include <vector>

class Solution {
public:
  long long maximumSubarraySum(vector<int> &nums, int k) {
    int n = nums.size();

    map<int, int> currentNums;
    long long sum = 0, maxSum = 0;
    for (int i = 0; i < k; i++) {
      currentNums[nums[i]]++;
      sum += nums[i];
    }
    if (currentNums.size() == k) {
      maxSum = max(maxSum, sum);
    }

    for (int i = 1; i <= n - k; i++) {
      currentNums[nums[i - 1]]--;
      sum -= nums[i - 1];
      if (currentNums[nums[i - 1]] == 0) {
        currentNums.erase(nums[i - 1]);
      }

      currentNums[nums[i + k - 1]]++;
      sum += nums[i + k - 1];

      if (currentNums.size() == k) {
        maxSum = max(maxSum, sum);
      }
    }

    return maxSum;
  }
};

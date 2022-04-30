// 560. Subarray Sum Equals K
// https://leetcode.com/problems/subarray-sum-equals-k/

#include <map>
#include <vector>

using namespace std;

class Solution {
 public:
  int subarraySum(vector<int>& nums, int k) {
    int count = 0, sum = 0;
    map<int, int> numberOfCountByPrefixSum;
    numberOfCountByPrefixSum.insert(make_pair(0, 1));

    for (auto& num : nums) {
      sum += num;

      if (numberOfCountByPrefixSum.find(sum - k) !=
          numberOfCountByPrefixSum.end()) {
        count += numberOfCountByPrefixSum[sum - k];
      }

      if (numberOfCountByPrefixSum.find(sum) !=
          numberOfCountByPrefixSum.end()) {
        numberOfCountByPrefixSum[sum] += 1;
      } else {
        numberOfCountByPrefixSum.insert(make_pair(sum, 1));
      }
    }

    return count;
  }
};

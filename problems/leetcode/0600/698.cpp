// 698. Partition to K Equal Sum Subsets
// https://leetcode.com/problems/partition-to-k-equal-sum-subsets/description/

using namespace std;

#include <numeric>
#include <vector>

class Solution {
public:
  int size = -1;
  vector<int> bunches;

  bool track(vector<int> &nums, int index) {
    if (index == nums.size()) {
      return true;
    }

    for (int i = 0; i < bunches.size(); i++) {
      bool result = false;
      if (bunches[i] + nums[index] <= size) {
        bunches[i] += nums[index];
        result = track(nums, index + 1);
        bunches[i] -= nums[index];
      }
      if (result) {
        return true;
      }
      if (bunches[i] == 0) {
        break;
      }
    }

    return false;
  }

  bool canPartitionKSubsets(vector<int> &nums, int k) {
    int sum = accumulate(nums.begin(), nums.end(), 0);
    if (sum % k != 0) {
      return false;
    }
    if (*max_element(nums.begin(), nums.end()) > (sum / k)) {
      return false;
    }

    size = sum / k;
    bunches = vector<int>(k, 0);

    return track(nums, 0);
  }
};

// 1. sum % k != 0이면 불가능.
// 2. 하나의 set이 (sum / k)의 합을 가져야만 함. 따라서 (최대값) > (sum / k)이면
// 불가능.
// 3. length가 16이므로 완전 탐색이 가능할 것 같음. -> 어떻게?

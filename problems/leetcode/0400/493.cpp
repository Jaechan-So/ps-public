// 493. Reverse Pairs
// https://leetcode.com/problems/reverse-pairs/

using namespace std;

#include <vector>

class Solution {
public:
  int reversePairs(vector<int> &nums) {
    return sortAndGetPairCount(nums, 0, nums.size() - 1);
  }

  int sortAndGetPairCount(vector<int> &nums, int start, int end) {
    if (start >= end) {
      return 0;
    }

    int currentStepPairCount = 0, leftIndex = start;
    int mid = (start + end) / 2;
    int leftCount = sortAndGetPairCount(nums, start, mid);
    int rightCount = sortAndGetPairCount(nums, mid + 1, end);

    for (int i = mid + 1; i <= end; i++) {
      while (leftIndex <= mid &&
             (long long)(nums[leftIndex]) <= 2 * (long long)nums[i]) {
        leftIndex++;
      }
      currentStepPairCount += mid - leftIndex + 1;
    }

    sort(nums.begin() + start, nums.begin() + end + 1);

    return leftCount + rightCount + currentStepPairCount;
  }
};

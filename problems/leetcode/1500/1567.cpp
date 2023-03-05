// 1567. Maximum Length of Subarray With Positive Product
// https://leetcode.com/problems/maximum-length-of-subarray-with-positive-product/description/

using namespace std;

#include <vector>

class Solution {
public:
  int getMaxLen(vector<int> &nums) {
    int maxLen = 0, negativeLen = 0, positiveLen = 0;

    for (int i = 0; i < nums.size(); i++) {
      if (nums[i] > 0) {
        if (negativeLen != 0) {
          negativeLen++;
        }
        positiveLen++;
        maxLen = max(maxLen, positiveLen);
      } else if (nums[i] < 0) {
        if (negativeLen != 0) {
          positiveLen++;
          negativeLen++;
          swap(positiveLen, negativeLen);
          maxLen = max(maxLen, positiveLen);
        } else {
          negativeLen = positiveLen + 1;
          maxLen = max(maxLen, positiveLen);
          positiveLen = 0;
        }
      } else {
        maxLen = max(maxLen, positiveLen);
        negativeLen = 0;
        positiveLen = 0;
      }
    }

    return maxLen;
  }
};

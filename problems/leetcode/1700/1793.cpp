// 1793. Maximum Score of a Good Subarray
// https://leetcode.com/problems/maximum-score-of-a-good-subarray/

using namespace std;

#include <vector>

class Solution {
public:
  int maximumScore(vector<int> &nums, int k) {
    int answer = nums[k], localMinimum = nums[k], length = nums.size();

    int i = k, j = k;
    while (i > 0 || j < length - 1) {
      if (i > 0 && j < length - 1) {
        if (nums[i - 1] >= nums[j + 1]) {
          localMinimum = min(localMinimum, nums[i - 1]);
          i--;
        } else {
          localMinimum = min(localMinimum, nums[j + 1]);
          j++;
        }
      } else if (i > 0 && j == length - 1) {
        localMinimum = min(localMinimum, nums[i - 1]);
        i--;
      } else if (i == 0 && j < length - 1) {
        localMinimum = min(localMinimum, nums[j + 1]);
        j++;
      }

      answer = max(answer, localMinimum * (j - i + 1));
    }

    return answer;
  }
};

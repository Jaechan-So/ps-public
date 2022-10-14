// 1885. Count Pairs in Two Arrays
// https://leetcode.com/problems/count-pairs-in-two-arrays/

using namespace std;

#include <vector>

class Solution {
public:
  long long countPairs(vector<int> &nums1, vector<int> &nums2) {
    int n = nums1.size();
    for (int i = 0; i < n; i++) {
      nums1[i] -= nums2[i];
    }

    sort(nums1.begin(), nums1.end());

    long long answer = 0;
    bool onlyPositive = false;
    for (int i = 0; i < n; i++) {
      if (onlyPositive) {
        answer += n - i - 1;
      } else {
        vector<int>::iterator iter =
            lower_bound(nums1.begin(), nums1.end(), -nums1[i] + 1);
        if (iter == nums1.end()) {
          continue;
        }
        if (*iter <= nums1[i]) {
          onlyPositive = true;
          answer += n - i - 1;
        } else {
          answer += n - (iter - nums1.begin());
        }
      }
    }

    return answer;
  }
};

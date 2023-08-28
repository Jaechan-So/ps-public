// 718. Maximum Length of Repeated Subarray
// https://leetcode.com/problems/maximum-length-of-repeated-subarray/description/

using namespace std;

#include <utility>
#include <vector>

class Solution {
public:
  int findLength(vector<int> &nums1, vector<int> &nums2) {
    int n1 = nums1.size(), n2 = nums2.size(), maxLength = 0;
    vector<int> prev(n2 + 1, 0), curr(n2 + 1, 0);

    for (int i = 0; i < n1; i++) {
      for (int j = 0; j < n2; j++) {
        if (nums1[i] == nums2[j]) {
          curr[j + 1] = prev[j] + 1;
          maxLength = max(maxLength, curr[j + 1]);
        } else {
          curr[j + 1] = 0;
        }
      }

      copy(curr.begin(), curr.end(), prev.begin());
    }

    return maxLength;
  }
};

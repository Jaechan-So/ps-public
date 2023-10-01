// 2871. Split Array Into Maximum Number of Subarrays
// https://leetcode.com/contest/biweekly-contest-114/problems/split-array-into-maximum-number-of-subarrays/
// Result: Accepted (with Wrong Answer 2 times)

using namespace std;

#include <vector>

class Solution {
public:
  int maxSubarrays(vector<int> &nums) {
    int totalSubArrays = 0, i = 0, current = 0;

    while (i < nums.size()) {
      current = nums[i++];

      while (i < nums.size()) {
        if (current == 0) {
          break;
        }
        current &= nums[i];
        i++;
      }

      totalSubArrays++;
    }

    if (totalSubArrays == 1) {
      return 1;
    }

    return current == 0 ? totalSubArrays : totalSubArrays - 1;
  }
};

// 직관: 마치 Monotonic Stack 혹은 Kadane 알고리즘 할 때 처럼, 줄어들면 계속
// 포함시키고 안 줄어들면 쳐낸다(?) [1,0,1,3] -> 싹 다 AND해야 0이 나옴.

// 기본적으로, 모두 AND를 때리면 모든 원소 중 가장 작은 원소보다 작거나 같은 값
// 나옴. 이 값보다 작아질 수 있는가? 안 될 것 같음. 따라서, 양 사이드에서 0이
// 되는 묶음끼리 빼는 것이 가장 Greedy하게 Subarray 개수를 늘릴 수 있을 것 같다.

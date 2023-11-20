// 1658. Minimum Operations to Reduce X to Zero
// https://leetcode.com/problems/minimum-operations-to-reduce-x-to-zero/description/

using namespace std;

#include <numeric>
#include <vector>

class Solution {
public:
  int minOperations(vector<int> &nums, int x) {
    int n = nums.size(), start = 0, end = 0, sum = 0,
        totalSum = accumulate(nums.begin(), nums.end(), 0),
        operations = INT_MAX;

    if (totalSum < x) {
      return -1;
    }

    while (end <= n) {
      if (totalSum - sum == x) {
        operations = min(operations, n - (end - start));
      }

      if (totalSum - sum < x) {
        sum -= nums[start];
        start++;

        if (start > end) {
          end = start;
          sum = 0;
        }
      } else {
        end++;

        if (end <= n) {
          sum += nums[end - 1];
        }
      }
    }

    return operations == INT_MAX ? -1 : operations;
  }
};

// Binary Search
// 1. 어차피 모두 양수로만 이루어져 있기 때문에, Prefix Sum을 만들면 무조건
// Strictly Increasing이다.
// 2. 따라서, 양 방향으로의 Prefix Sum을 만들어놓고, 한 쪽을 순회하면서 x -
// (oneSidePrefixSum)을 Binary Search로 찾으면 된다.
// 3. 이 때 Index의 합이 n을 넘어가면 안 된다.

// Two Pointers
// 1. 전체 Sum - Subarray의 Sum == x인 곳을 찾으면 된다.

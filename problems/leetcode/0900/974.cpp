// 974. Subarray Sums Divisible by K
// https://leetcode.com/problems/subarray-sums-divisible-by-k/description/

using namespace std;

#include <vector>

class Solution {
public:
  int getSafeRemainder(int num, int k) {
    return num >= 0 ? num % k : (k - (-num % k)) % k;
  }

  int subarraysDivByK(vector<int> &nums, int k) {
    vector<int> remainderCounts(k, 0);
    int remainderZeroIndex = 0, subarrayCount = 0;

    for (int &num : nums) {
      remainderZeroIndex =
          getSafeRemainder(remainderZeroIndex - getSafeRemainder(num, k), k);
      int numIndex =
          getSafeRemainder(remainderZeroIndex + getSafeRemainder(num, k), k);
      remainderCounts[numIndex]++;
      subarrayCount += remainderCounts[remainderZeroIndex];
    }

    return subarrayCount;
  }
};

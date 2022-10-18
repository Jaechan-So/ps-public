// 525. Contiguous Array
// https://leetcode.com/problems/contiguous-array/

using namespace std;

#include <unordered_map>
#include <vector>

class Solution {
public:
  int findMaxLength(vector<int> &nums) {
    unordered_map<int, int> recentIndex;
    recentIndex[0] = -1;

    int maxLength = 0, numberOfMoreOne = 0;
    for (int i = 0; i < nums.size(); i++) {
      numberOfMoreOne += (nums[i] == 1 ? 1 : -1);
      if (recentIndex.find(numberOfMoreOne) != recentIndex.end()) {
        maxLength = max(maxLength, i - recentIndex[numberOfMoreOne]);
      } else {
        recentIndex[numberOfMoreOne] = i;
      }
    }

    return maxLength;
  }
};

// 992. Subarrays with K Different Integers
// https://leetcode.com/problems/subarrays-with-k-different-integers/

using namespace std;

#include <unordered_map>
#include <vector>

class Solution {
public:
  int subarraysWithKDistinct(vector<int> &nums, int k) {
    return withMostKDistincts(nums, k) - withMostKDistincts(nums, k - 1);
  }

  int withMostKDistincts(vector<int> &nums, int k) {
    int start = 0, answer = 0;
    unordered_map<int, int> count;

    for (int end = 0; end < nums.size(); end++) {
      if (count[nums[end]] == 0) {
        k--;
      }
      count[nums[end]]++;

      while (k < 0) {
        count[nums[start]]--;
        if (count[nums[start]] == 0) {
          k++;
        }
        start++;
      }

      answer += (end - start + 1);
    }

    return answer;
  }
};

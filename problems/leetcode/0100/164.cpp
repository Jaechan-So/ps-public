// 164. Maximum Gap
// https://leetcode.com/problems/maximum-gap/

using namespace std;

#include <vector>

class Solution {
public:
  int RADIX = 10;

  int maximumGap(vector<int> &nums) {
    if (nums.size() < 2) {
      return 0;
    }

    vector<int> elements(nums.size());
    int exponent = 1, maxElement = *max_element(nums.begin(), nums.end());

    while (maxElement >= exponent) {
      vector<int> count(RADIX, 0);

      for (int i = 0; i < nums.size(); i++) {
        count[(nums[i] / exponent) % 10]++;
      }

      for (int i = 1; i < count.size(); i++) {
        count[i] += count[i - 1];
      }

      for (int i = nums.size() - 1; i >= 0; i--) {
        int index = count[(nums[i] / exponent) % 10] - 1;
        elements[index] = nums[i];
        count[(nums[i] / exponent) % 10]--;
      }

      for (int i = 0; i < nums.size(); i++) {
        nums[i] = elements[i];
      }

      exponent *= 10;
    }

    int answer = 0;
    for (int i = 0; i < nums.size() - 1; i++) {
      answer = max(answer, nums[i + 1] - nums[i]);
    }

    return answer;
  }
};

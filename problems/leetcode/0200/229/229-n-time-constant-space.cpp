// 229. Majority Element II
// https://leetcode.com/problems/majority-element-ii/description/

using namespace std;

#include <vector>

class Solution {
public:
  vector<int> majorityElement(vector<int> &nums) {
    int firstMajorNum = INT_MIN, firstMajorNumCount = 0,
        secondMajorNum = INT_MIN, secondMajorNumCount = 0;

    for (int num : nums) {
      if (num == firstMajorNum && firstMajorNumCount > 0) {
        firstMajorNumCount++;
      } else if (num == secondMajorNum && secondMajorNumCount > 0) {
        secondMajorNumCount++;
      } else if (firstMajorNumCount == 0) {
        firstMajorNumCount++;
        firstMajorNum = num;
      } else if (secondMajorNumCount == 0) {
        secondMajorNumCount++;
        secondMajorNum = num;
      } else {
        firstMajorNumCount--;
        secondMajorNumCount--;
      }
    }

    firstMajorNumCount = 0;
    secondMajorNumCount = 0;
    for (int num : nums) {
      if (firstMajorNum == num) {
        firstMajorNumCount++;
      } else if (secondMajorNum == num) {
        secondMajorNumCount++;
      }
    }

    vector<int> majorityElements;
    if (firstMajorNumCount > (nums.size() / 3)) {
      majorityElements.push_back(firstMajorNum);
    }
    if (secondMajorNumCount > (nums.size() / 3)) {
      majorityElements.push_back(secondMajorNum);
    }
    return majorityElements;
  }
};

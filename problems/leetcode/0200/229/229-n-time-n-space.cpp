// 229. Majority Element II
// https://leetcode.com/problems/majority-element-ii/description/

using namespace std;

#include <map>
#include <vector>

class Solution {
public:
  vector<int> majorityElement(vector<int> &nums) {
    map<int, int> numCounts;

    for (int num : nums) {
      numCounts[num]++;
    }

    vector<int> majorityElements;
    for (pair<int, int> numAndNumCountPair : numCounts) {
      if (numAndNumCountPair.second > nums.size() / 3) {
        majorityElements.push_back(numAndNumCountPair.first);
      }
    }

    return majorityElements;
  }
};

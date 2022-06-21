// 2248. Intersection of Multiple Arrays
// https://leetcode.com/problems/intersection-of-multiple-arrays/

#include <map>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<int> intersection(vector<vector<int>>& nums) {
    int length = nums.size();

    map<int, int> numCounts;
    vector<int> answer;

    for (auto& arr : nums) {
      for (auto& elem : arr) {
        if (numCounts.find(elem) != numCounts.end()) {
          numCounts[elem]++;
        } else {
          numCounts[elem] = 1;
        }
      }
    }

    for (auto& numCount : numCounts) {
      if (numCount.second == length) {
        answer.push_back(numCount.first);
      }
    }

    return answer;
  }
};

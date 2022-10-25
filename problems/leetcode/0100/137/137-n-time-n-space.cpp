// 137. Single Number II
// https://leetcode.com/problems/single-number-ii/

using namespace std;

#include <unordered_map>
#include <vector>

class Solution {
public:
  int singleNumber(vector<int> &nums) {
    unordered_map<int, int> numAndCount;
    for (auto num : nums) {
      numAndCount[num]++;
    }

    int answer = 0;
    for (auto p : numAndCount) {
      int num = p.first, count = p.second;
      if (count == 1) {
        answer = num;
      }
    }
    return answer;
  }
};

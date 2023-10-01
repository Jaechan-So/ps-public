// 2870. Minimum Number of Operations to Make Array Empty
// https://leetcode.com/contest/biweekly-contest-114/problems/minimum-number-of-operations-to-make-array-empty/
// Result: Accepted

using namespace std;

#include <unordered_map>
#include <vector>

class Solution {
public:
  int minOperations(vector<int> &nums) {
    unordered_map<int, int> counts;

    for (int num : nums) {
      counts[num]++;
    }

    int totalOperations = 0;
    for (unordered_map<int, int>::iterator iter = counts.begin();
         iter != counts.end(); iter++) {
      int count = iter->second;

      if (count <= 1) {
        return -1;
      }

      if (count % 3 == 0) {
        totalOperations += (count / 3);
      } else if (count % 3 == 1) {
        totalOperations += (((count - 4) / 3) + 2);
      } else {
        totalOperations += (((count - 2) / 3) + 1);
      }
    }

    return totalOperations;
  }
};

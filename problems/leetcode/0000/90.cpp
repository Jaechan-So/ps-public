// 90. Subsets II
// https://leetcode.com/problems/subsets-ii/description/

using namespace std;

#include <map>
#include <vector>

class Solution {
public:
  vector<vector<int>> subsets;
  vector<int> currentSubsetEntry;

  vector<vector<int>> subsetsWithDup(vector<int> &nums) {
    map<int, int> numCounts;
    for (int i = 0; i < nums.size(); i++) {
      numCounts[nums[i]]++;
    }

    appendSubsetEntries(numCounts, numCounts.begin());

    return subsets;
  }

  void appendSubsetEntries(map<int, int> &numCounts,
                           map<int, int>::iterator iter) {
    if (iter == numCounts.end()) {
      subsets.push_back(vector<int>(currentSubsetEntry));
      return;
    }

    int key = iter->first, count = iter->second;

    appendSubsetEntries(numCounts, ++iter);
    iter--;

    for (int i = 0; i < count; i++) {
      currentSubsetEntry.push_back(key);
      appendSubsetEntries(numCounts, ++iter);
      iter--;
    }

    for (int i = 0; i < count; i++) {
      currentSubsetEntry.pop_back();
    }
  }
};

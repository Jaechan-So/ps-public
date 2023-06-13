// 946. Validate Stack Sequences
// https://leetcode.com/problems/validate-stack-sequences/description/

using namespace std;

#include <map>
#include <vector>

class Solution {
public:
  bool validateStackSequences(vector<int> &pushed, vector<int> &popped) {
    int n = pushed.size();

    map<int, int> pushedValueToIndex;
    for (int i = 0; i < n; i++) {
      pushedValueToIndex[pushed[i]] = i;
    }

    vector<int> s;
    int pushedIndex = 0;
    for (int i = 0; i < n; i++) {
      int target = popped[i];

      while (pushedIndex < n && pushedIndex <= pushedValueToIndex[target]) {
        s.push_back(pushed[pushedIndex++]);
      }

      if (!s.empty() && s.back() == target) {
        s.pop_back();
      }
    }

    return s.size() == 0;
  }
};

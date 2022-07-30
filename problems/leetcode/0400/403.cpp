// 403. Frog Jump
// https://leetcode.com/problems/frog-jump/

using namespace std;

#include <map>
#include <set>
#include <vector>

class Solution {
public:
  bool canCross(vector<int> &stones) {
    int count = stones.size();

    map<int, set<int>> possibleSteps;
    for (auto &stone : stones) {
      possibleSteps.insert({stone, set<int>()});
    }

    possibleSteps[0].insert(0);
    for (auto &stone : stones) {
      for (auto &step : possibleSteps[stone]) {
        for (int stepCandidate = step - 1; stepCandidate <= step + 1;
             stepCandidate++) {
          if (stepCandidate > 0 && possibleSteps.find(stone + stepCandidate) !=
                                       possibleSteps.end()) {
            possibleSteps[stone + stepCandidate].insert(stepCandidate);
          }
        }
      }
    }

    return possibleSteps[stones[count - 1]].size() > 0;
  }
};

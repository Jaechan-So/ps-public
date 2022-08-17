// 39. Combination Sum
// https://leetcode.com/problems/combination-sum/

using namespace std;

#include <vector>

class Solution {
public:
  vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
    vector<vector<int>> answer;
    int candidateCount = candidates.size(), remainingTarget = target;
    vector<int> currentCombination;

    backtracking(answer, candidates, currentCombination, 0, target);

    return answer;
  }

  void backtracking(vector<vector<int>> &answer, vector<int> &candidates,
                    vector<int> &currentCombination, int index,
                    int remainingTarget) {
    if (candidates.size() <= index) {
      return;
    }

    int target = remainingTarget, candidate = candidates[index];

    while (target > 0) {
      backtracking(answer, candidates, currentCombination, index + 1, target);
      currentCombination.push_back(candidate);
      target -= candidate;
    }

    if (target == 0) {
      vector<int> possibleCombination(currentCombination);
      answer.push_back(possibleCombination);
    }

    while (target < remainingTarget) {
      currentCombination.pop_back();
      target += candidate;
    }
  }
};

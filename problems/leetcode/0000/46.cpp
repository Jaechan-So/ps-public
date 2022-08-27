// 46. Permutations
// https://leetcode.com/problems/permutations/

using namespace std;

#include <set>
#include <vector>

class Solution {
public:
  vector<vector<int>> permute(vector<int> &nums) {
    vector<vector<int>> answer;

    set<int> indicies;
    vector<int> permutations;
    for (int i = 0; i < nums.size(); i++) {
      indicies.insert(i);
    }

    backtracking(answer, nums, indicies, permutations);

    return answer;
  }

  void backtracking(vector<vector<int>> &answer, vector<int> &nums,
                    set<int> &indicies, vector<int> &permutations) {
    if (permutations.size() == nums.size()) {
      answer.push_back(vector<int>(permutations));
      return;
    }

    set<int> childrenIndicies(indicies);

    for (auto index : indicies) {
      childrenIndicies.erase(index);
      permutations.push_back(nums[index]);

      backtracking(answer, nums, childrenIndicies, permutations);

      childrenIndicies.insert(index);
      permutations.pop_back();
    }
  }
};

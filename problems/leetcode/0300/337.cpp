// 337. House Robber III
// https://leetcode.com/problems/house-robber-iii/description/

using namespace std;

#include <algorithm>

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

class Solution {
public:
  int rob(TreeNode *root) {
    pair<int, int> results = dfs(root);
    return max(results.first, results.second);
  }

  pair<int, int> dfs(TreeNode *node) {
    if (!node) {
      return {0, 0};
    }

    pair<int, int> leftResults = {0, 0}, rightResults = {0, 0};
    if (node->left) {
      leftResults = dfs(node->left);
    }
    if (node->right) {
      rightResults = dfs(node->right);
    }

    int withoutNodeResultCandidates[4] = {
        leftResults.first + rightResults.first,
        leftResults.first + rightResults.second,
        leftResults.second + rightResults.first,
        leftResults.second + rightResults.second,
    };

    return {
        node->val + leftResults.second + rightResults.second,
        *max_element(withoutNodeResultCandidates,
                     withoutNodeResultCandidates + 4),
    };
  }
};

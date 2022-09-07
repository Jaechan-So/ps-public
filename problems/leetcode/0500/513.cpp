// 513. Find Bottom Left Tree Value
// https://leetcode.com/problems/find-bottom-left-tree-value/

using namespace std;

#include <utility>

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

typedef pair<int, int> pii; // (value, height)

class Solution {
public:
  int findBottomLeftValue(TreeNode *root) { return dfs(root, 1).first; }

  pii dfs(TreeNode *node, int height) {
    if (!node) {
      return {0, 0};
    }

    if (!node->left && !node->right) {
      return {node->val, height};
    }

    pii leftValueAndHeight = dfs(node->left, height + 1);
    pii rightValueAndHeight = dfs(node->right, height + 1);

    return leftValueAndHeight.second >= rightValueAndHeight.second
               ? leftValueAndHeight
               : rightValueAndHeight;
  }
};

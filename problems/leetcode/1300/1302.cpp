// 1302. Deepest Leaves Sum
// https://leetcode.com/problems/deepest-leaves-sum/

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
  int height = 0, sum = 0;

  int deepestLeavesSum(TreeNode *root) {
    dfs(root, 1);
    return sum;
  }

  void dfs(TreeNode *node, int nodeHeight) {
    if (!node) {
      return;
    }

    if (node->left || node->right) {
      dfs(node->left, nodeHeight + 1);
      dfs(node->right, nodeHeight + 1);
    }

    if (nodeHeight > height) {
      height = nodeHeight;
      sum = node->val;
    } else if (nodeHeight == height) {
      sum += node->val;
    }
  }
};

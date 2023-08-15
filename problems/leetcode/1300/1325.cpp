// 1325. Delete Leaves With a Given Value
// https://leetcode.com/problems/delete-leaves-with-a-given-value/description/

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
  TreeNode *removeLeafNodes(TreeNode *root, int target) {
    if (root->left) {
      root->left = removeLeafNodes(root->left, target);
    }

    if (root->right) {
      root->right = removeLeafNodes(root->right, target);
    }

    if (!root->left && !root->right && root->val == target) {
      return nullptr;
    }

    return root;
  }
};

// 101. Symmetric Tree
// https://leetcode.com/problems/symmetric-tree/

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
  bool isBothNull(TreeNode *left, TreeNode *right) {
    return left == nullptr && right == nullptr;
  }

  bool isOnlyOneNull(TreeNode *left, TreeNode *right) {
    return (left == nullptr && right != nullptr) ||
           (left != nullptr && right == nullptr);
  }

  bool hasDifferentVal(TreeNode *left, TreeNode *right) {
    return left->val != right->val;
  }

  bool isSymmetricEqual(TreeNode *left, TreeNode *right) {
    if (isBothNull(left, right)) {
      return true;
    }
    if (isOnlyOneNull(left, right)) {
      return false;
    }
    if (hasDifferentVal(left, right)) {
      return false;
    }
    return isSymmetricEqual(left->left, right->right) &&
           isSymmetricEqual(left->right, right->left);
  }

  bool isSymmetric(TreeNode *root) {
    return isSymmetricEqual(root->left, root->right);
  }
};

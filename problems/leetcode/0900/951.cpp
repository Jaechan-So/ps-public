// 951. Flip Equivalent Binary Trees
// https://leetcode.com/problems/flip-equivalent-binary-trees/

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
  bool flipEquiv(TreeNode *root1, TreeNode *root2) {
    if (isBothNodeNull(root1, root2)) {
      return true;
    }

    if (isOnlyOneNodeNull(root1, root2)) {
      return false;
    }

    if (isNodeValDifferent(root1, root2)) {
      return false;
    }

    if (isEquivNode(root1->left, root2->left) &&
        isEquivNode(root1->right, root2->right)) {
      return flipEquiv(root1->left, root2->left) &&
             flipEquiv(root1->right, root2->right);
    }

    if (isEquivNode(root1->left, root2->right) &&
        isEquivNode(root1->right, root2->left)) {
      return flipEquiv(root1->left, root2->right) &&
             flipEquiv(root1->right, root2->left);
    }

    return false;
  }
  bool isBothNodeNull(TreeNode *node1, TreeNode *node2) {
    return !node1 && !node2;
  }
  bool isOnlyOneNodeNull(TreeNode *node1, TreeNode *node2) {
    return (!node1 && node2) || (node1 && !node2);
  }
  bool isNodeValDifferent(TreeNode *node1, TreeNode *node2) {
    return node1->val != node2->val;
  }
  bool isNodeValSame(TreeNode *node1, TreeNode *node2) {
    return node1 && node2 && node1->val == node2->val;
  }
  bool isEquivNode(TreeNode *node1, TreeNode *node2) {
    return isBothNodeNull(node1, node2) || isNodeValSame(node1, node2);
  }
};

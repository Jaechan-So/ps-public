// 538. Convert BST to Greater Tree
// https://leetcode.com/problems/convert-bst-to-greater-tree/description/

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
  int getSumOfAll(TreeNode *node) {
    if (!node) {
      return 0;
    }

    int sum = node->val;
    if (node->left) {
      sum += getSumOfAll(node->left);
    }
    if (node->right) {
      sum += getSumOfAll(node->right);
    }

    return sum;
  }

  void inOrderTraversal(TreeNode *node, int &sum) {
    if (!node) {
      return;
    }

    inOrderTraversal(node->left, sum);

    int prevVal = node->val;
    node->val = sum;
    sum -= prevVal;

    inOrderTraversal(node->right, sum);
  }

  TreeNode *convertBST(TreeNode *root) {
    int sum = getSumOfAll(root);
    inOrderTraversal(root, sum);
    return root;
  }
};

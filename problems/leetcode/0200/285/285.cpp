// 285. Inorder Successor in BST
// https://leetcode.com/problems/inorder-successor-in-bst/

using namespace std;

#include <cstddef>

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
  TreeNode *inorderSuccessor(TreeNode *root, TreeNode *p) {
    bool isSuccessor = false;
    return inorderTraversal(root, p, isSuccessor);
  }

  TreeNode *inorderTraversal(TreeNode *node, TreeNode *p, bool &isSuccessor) {
    if (node->left) {
      TreeNode *left = inorderTraversal(node->left, p, isSuccessor);
      if (left) {
        return left;
      }
    }

    if (isSuccessor) {
      return node;
      isSuccessor = false;
    }

    if (node == p) {
      isSuccessor = true;
    }

    if (node->right) {
      TreeNode *right = inorderTraversal(node->right, p, isSuccessor);
      if (right) {
        return right;
      }
    }

    return nullptr;
  }
};

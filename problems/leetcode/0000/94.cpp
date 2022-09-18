// 94. Binary Tree Inorder Traversal
// https://leetcode.com/problems/binary-tree-inorder-traversal/

using namespace std;

#include <vector>

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
  vector<int> nodes;

  void traversal(TreeNode *root) {
    if (!root) {
      return;
    }

    traversal(root->left);
    nodes.push_back(root->val);
    traversal(root->right);
  }

  vector<int> inorderTraversal(TreeNode *root) {
    traversal(root);
    return nodes;
  }
};

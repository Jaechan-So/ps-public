// 669. Trim a Binary Search Tree
// https://leetcode.com/problems/trim-a-binary-search-tree/description/

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
  TreeNode *trimBST(TreeNode *root, int low, int high) {
    if (!root) {
      return root;
    }

    TreeNode *trimmedLeft = trimBST(root->left, low, high),
             *trimmedRight = trimBST(root->right, low, high);

    if (low <= root->val && root->val <= high) {
      root->left = trimmedLeft;
      root->right = trimmedRight;
      return root;
    }

    return trimmedLeft ? trimmedLeft : trimmedRight;
  }
};

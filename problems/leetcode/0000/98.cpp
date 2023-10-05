// 98. Validate Binary Search Tree
// https://leetcode.com/problems/validate-binary-search-tree/description/

using namespace std;

#include <climits>

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
  bool isValidRange(TreeNode *node, int start, int end) {
    if (!(start <= node->val && node->val <= end)) {
      return false;
    }

    bool valid = true;
    if (node->left) {
      if (node->val == INT_MIN) {
        valid = false;
      } else {
        valid = valid && isValidRange(node->left, start, node->val - 1);
      }
    }
    if (node->right) {
      if (node->val == INT_MAX) {
        valid = false;
      } else {
        valid = valid && isValidRange(node->right, node->val + 1, end);
      }
    }

    return valid;
  }

  bool isValidBST(TreeNode *root) {
    return isValidRange(root, INT_MIN, INT_MAX);
  }
};

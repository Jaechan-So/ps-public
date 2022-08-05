// 450. Delete Node in a BST
// https://leetcode.com/problems/delete-node-in-a-bst/

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
  TreeNode *deleteNode(TreeNode *root, int key) {
    if (!root) {
      return root;
    }

    if (key < root->val) {
      if (root->left) {
        root->left = deleteNode(root->left, key);
      }
      return root;
    } else if (key == root->val) {
      if (root->left) {
        TreeNode *right = root->right;

        if (right) {
          TreeNode *target = root->left;
          while (target->right) {
            target = target->right;
          }
          target->right = right;
        }

        return root->left;
      }

      return root->right;
    } else {
      if (root->right) {
        root->right = deleteNode(root->right, key);
      }
      return root;
    }
  }
};

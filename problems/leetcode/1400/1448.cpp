// 1448. Count Good Nodes in Binary Tree
// https://leetcode.com/problems/count-good-nodes-in-binary-tree/

using namespace std;

#include <algorithm>

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
  int goodNodes(TreeNode *root) { return getGoodNodeCount(root, INT_MIN); }

  int getGoodNodeCount(TreeNode *node, int maxVal) {
    if (!node) {
      return 0;
    }

    bool isGoodNode = node->val >= maxVal;

    return getGoodNodeCount(node->left, max(node->val, maxVal)) +
           getGoodNodeCount(node->right, max(node->val, maxVal)) +
           (isGoodNode ? 1 : 0);
  }
};

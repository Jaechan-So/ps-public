// 102. Binary Tree Level Order Traversal
// https://leetcode.com/problems/binary-tree-level-order-traversal/

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
  vector<vector<int>> levelOrderNodes;

  void appendToLevelOrderNodes(int val, int level) {
    if (levelOrderNodes.size() <= level) {
      while (levelOrderNodes.size() <= level) {
        vector<int> newLevel;
        levelOrderNodes.push_back(newLevel);
      }
    }
    levelOrderNodes[level].push_back(val);
  }

  void dfs(TreeNode *root, int level) {
    if (!root) {
      return;
    }
    appendToLevelOrderNodes(root->val, level);
    dfs(root->left, level + 1);
    dfs(root->right, level + 1);
  }

  vector<vector<int>> levelOrder(TreeNode *root) {
    dfs(root, 0);
    return levelOrderNodes;
  }
};

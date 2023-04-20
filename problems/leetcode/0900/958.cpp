// 958. Check Completeness of a Binary Tree
// https://leetcode.com/problems/check-completeness-of-a-binary-tree/description/

#include <queue>

using namespace std;

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
  bool isCompleteRow(queue<pair<TreeNode *, int>> &indicies, int &prev) {
    for (int i = 0; i < indicies.size(); i++) {
      TreeNode *node = indicies.front().first;
      int index = indicies.front().second;
      if (index != prev + 1) {
        return false;
      }
      if (node->left) {
        indicies.push({node->left, 2 * index});
      }
      if (node->right) {
        indicies.push({node->right, 2 * index + 1});
      }
      indicies.pop();
      prev = index;
    }
    return true;
  }

  bool isCompleteTree(TreeNode *root) {
    queue<pair<TreeNode *, int>> indicies;
    indicies.push({root, 1});

    int prev = 0;
    while (!indicies.empty()) {
      if (!isCompleteRow(indicies, prev)) {
        return false;
      }
    }

    return true;
  }
};

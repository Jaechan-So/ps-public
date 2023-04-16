// 107. Binary Tree Level Order Traversal II
// https://leetcode.com/problems/binary-tree-level-order-traversal-ii/description/

#include <queue>
#include <vector>

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
  void traverse(vector<vector<int>> &result, queue<TreeNode *> nodes) {
    if (nodes.empty()) {
      return;
    }

    vector<int> currentLevelNodes;
    int iterationCount = nodes.size();
    for (int i = 0; i < iterationCount; i++) {
      TreeNode *currentLevelNode = nodes.front();
      nodes.pop();

      currentLevelNodes.push_back(currentLevelNode->val);

      if (currentLevelNode->left) {
        nodes.push(currentLevelNode->left);
      }
      if (currentLevelNode->right) {
        nodes.push(currentLevelNode->right);
      }
    }

    traverse(result, nodes);

    result.push_back(currentLevelNodes);
    return;
  }

  vector<vector<int>> levelOrderBottom(TreeNode *root) {
    vector<vector<int>> result;
    if (!root) {
      return result;
    }

    queue<TreeNode *> nodes({root});

    traverse(result, nodes);

    return result;
  }
};

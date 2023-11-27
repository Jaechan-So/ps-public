// 103. Binary Tree Zigzag Level Order Traversal
// https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/description/

using namespace std;

#include <queue>
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
  vector<vector<int>> nodes;

  vector<vector<int>> zigzagLevelOrder(TreeNode *root) {
    queue<pair<TreeNode *, int>> q;
    q.push({root, 0});

    while (!q.empty()) {
      TreeNode *node = q.front().first;
      int depth = q.front().second;
      q.pop();

      if (!node) {
        continue;
      }

      if (nodes.size() < depth + 1) {
        nodes.push_back(vector<int>());
      }
      nodes[depth].push_back(node->val);

      if (node->left) {
        q.push({node->left, depth + 1});
      }
      if (node->right) {
        q.push({node->right, depth + 1});
      }
    }

    for (int i = 1; i < nodes.size(); i += 2) {
      int n = nodes[i].size();
      for (int j = 0; j < (n / 2); j++) {
        swap(nodes[i][j], nodes[i][n - 1 - j]);
      }
    }

    return nodes;
  }
};

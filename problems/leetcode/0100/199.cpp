// 199. Binary Tree Right Side View
// https://leetcode.com/problems/binary-tree-right-side-view/description/

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
  vector<int> rightSideView(TreeNode *root) {
    vector<int> rightNodes;

    queue<pair<TreeNode *, int>> q;

    if (root) {
      q.push({root, 1});
    }

    while (!q.empty()) {
      TreeNode *node = q.front().first;
      int height = q.front().second;
      q.pop();

      if (node->left) {
        q.push({node->left, height + 1});
      }
      if (node->right) {
        q.push({node->right, height + 1});
      }

      if (q.empty() || height < q.front().second) {
        rightNodes.push_back(node->val);
      }
    }

    return rightNodes;
  }
};

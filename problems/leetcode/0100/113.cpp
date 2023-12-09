// 113. Path Sum II
// https://leetcode.com/problems/path-sum-ii/description/

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
  vector<vector<int>> paths;

  void dfs(TreeNode *node, vector<int> &path, int prevSum, int targetSum) {
    if (!node) {
      return;
    }

    path.push_back(node->val);

    int sum = prevSum + node->val;
    if (sum == targetSum && !node->left && !node->right) {
      paths.push_back(path);
    }

    dfs(node->left, path, sum, targetSum);
    dfs(node->right, path, sum, targetSum);

    path.pop_back();
  }

  vector<vector<int>> pathSum(TreeNode *root, int targetSum) {
    vector<int> path;
    dfs(root, path, 0, targetSum);
    return paths;
  }
};

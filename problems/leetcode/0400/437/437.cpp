// 437. Path Sum III
// https://leetcode.com/problems/path-sum-iii/description/

using namespace std;

#include <unordered_map>

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
  unordered_map<long long, int> sums;

  int traverse(TreeNode *node, int targetSum, long long currentSum) {
    if (!node) {
      return 0;
    }

    int paths = 0;
    currentSum += node->val;
    paths += sums[currentSum - targetSum];
    sums[currentSum]++;
    if (node->left) {
      paths += traverse(node->left, targetSum, currentSum);
    }
    if (node->right) {
      paths += traverse(node->right, targetSum, currentSum);
    }
    sums[currentSum]--;

    return paths;
  }

  int pathSum(TreeNode *root, int targetSum) {
    sums[0] = 1;
    return traverse(root, targetSum, 0);
  }
};

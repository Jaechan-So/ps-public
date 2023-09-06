// 1161. Maximum Level Sum of a Binary Tree
// https://leetcode.com/problems/maximum-level-sum-of-a-binary-tree/description/

using namespace std;

#include <queue>

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
  int maxLevelSum(TreeNode *root) {
    queue<pair<TreeNode *, int>> q;
    q.push({root, 1});

    int currentLevel = 1, currentLevelSum = root->val, maxSum = root->val,
        levelWithMaxSum = 1;
    while (!q.empty()) {
      TreeNode *node = q.front().first;
      int level = q.front().second;
      q.pop();

      if (currentLevel < level) {
        if (currentLevelSum > maxSum) {
          maxSum = currentLevelSum;
          levelWithMaxSum = currentLevel;
        }

        currentLevel = level;
        currentLevelSum = 0;
      }

      currentLevelSum += node->val;

      if (node->left) {
        q.push({node->left, level + 1});
      }
      if (node->right) {
        q.push({node->right, level + 1});
      }
    }

    if (currentLevelSum > maxSum) {
      maxSum = currentLevelSum;
      levelWithMaxSum = currentLevel;
    }

    return levelWithMaxSum;
  }
};

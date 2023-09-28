// 124. Binary Tree Maximum Path Sum
// https://leetcode.com/problems/binary-tree-maximum-path-sum/description/

using namespace std;

#include <algorithm>
#include <climits>

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
  int maxSum = INT_MIN;

  int dfs(TreeNode *node) {
    int localMaxSum = node->val, left = INT_MIN, right = INT_MIN;

    if (node->left) {
      left = dfs(node->left);
      localMaxSum = max(localMaxSum, node->val + left);
    }
    if (node->right) {
      right = dfs(node->right);
      localMaxSum = max(localMaxSum, node->val + right);
    }

    int possiblePathSum = localMaxSum;
    if (left != INT_MIN && right != INT_MIN) {
      possiblePathSum = max(possiblePathSum, left + right + node->val);
    }
    maxSum = max(maxSum, possiblePathSum);

    return localMaxSum;
  }

  int maxPathSum(TreeNode *root) {
    dfs(root);
    return maxSum;
  }
};

// 한 쪽으로만 내려가면서 합의 최댓값을 안다면,
// 양 쪽의 합은 그 노드를 중심으로 하는 값의 최대값.
// 자기 자신, 양 쪽에서 한 쪽으로만 가는 것들의 최대값, 양 쪽 둘다 한 쪽으로만
// 가는 것들의 최대값의 합, 양 쪽에서 각각 알아서 하는 것들의 최대값

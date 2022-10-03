// 104. Maximum Depth of Binary Tree
// https://leetcode.com/problems/maximum-depth-of-binary-tree/

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
  int maxDepth(TreeNode *root) {
    if (!root)
      return 0;

    int answer = 1;
    queue<pair<TreeNode *, int>> q;
    q.push(pair<TreeNode *, int>(root, 1));

    while (!q.empty()) {
      pair<TreeNode *, int> curr = q.front();
      answer = max(answer, curr.second);
      q.pop();
      if (curr.first->left) {
        q.push(pair<TreeNode *, int>(curr.first->left, curr.second + 1));
      }
      if (curr.first->right) {
        q.push(pair<TreeNode *, int>(curr.first->right, curr.second + 1));
      }
    }

    return answer;
  }
};

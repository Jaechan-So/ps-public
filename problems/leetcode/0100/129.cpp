// 129. Sum Root to Leaf Numbers
// https://leetcode.com/problems/sum-root-to-leaf-numbers/

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
  int sumNumbers(TreeNode *root) {
    int answer = 0;
    sumOfNode(root, 0, answer);
    return answer;
  }

  void sumOfNode(TreeNode *node, int sum, int &answer) {
    if (!node->left && !node->right) {
      answer += sum * 10 + node->val;
      return;
    }

    if (node->left) {
      sumOfNode(node->left, sum * 10 + node->val, answer);
    }

    if (node->right) {
      sumOfNode(node->right, sum * 10 + node->val, answer);
    }
  }
};

#define abs(x) ((x) >= 0 ? (x) : (-(x)))

using namespace std;

#include <algorithm>
#include <utility>

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
  int answer = 0;
  int maxAncestorDiff(TreeNode *root) {
    traverse(root);
    return answer;
  }

  pair<int, int> traverse(TreeNode *node) {
    // Handle leaf node case.
    if (!node->left && !node->right) {
      return make_pair(0, 0);
    }

    if (node->left && !node->right) {
      pair<int, int> leftMinMaxPair = traverse(node->left);
      int childDiff = node->val - node->left->val;

      // 3 cases: Difference with child, Difference with child's minimum case,
      // Difference with child's maximum case.
      answer = max(answer, max(abs(childDiff),
                               max(abs(leftMinMaxPair.first + childDiff),
                                   abs(leftMinMaxPair.second + childDiff))));
      return make_pair(min(leftMinMaxPair.first + childDiff, childDiff),
                       max(leftMinMaxPair.second + childDiff, childDiff));
    }

    if (!node->left && node->right) {
      pair<int, int> rightMinMaxPair = traverse(node->right);
      int childDiff = node->val - node->right->val;

      // Ditto.
      answer = max(answer, max(abs(childDiff),
                               max(abs(rightMinMaxPair.first + childDiff),
                                   abs(rightMinMaxPair.second + childDiff))));
      return make_pair(min(rightMinMaxPair.first + childDiff, childDiff),
                       max(rightMinMaxPair.second + childDiff, childDiff));
    }

    pair<int, int> leftMinMaxPair = traverse(node->left);
    int leftChildDiff = node->val - node->left->val;

    pair<int, int> rightMinMaxPair = traverse(node->right);
    int rightChildDiff = node->val - node->right->val;

    int minVal =
        min(leftChildDiff,
            min(rightChildDiff, min(leftMinMaxPair.first + leftChildDiff,
                                    rightMinMaxPair.first + rightChildDiff)));
    int maxVal =
        max(leftChildDiff,
            max(rightChildDiff, max(leftMinMaxPair.second + leftChildDiff,
                                    rightMinMaxPair.second + rightChildDiff)));

    // Composition of above two cases.
    answer = max(answer, max(abs(minVal), abs(maxVal)));

    return make_pair(minVal, maxVal);
  }
};

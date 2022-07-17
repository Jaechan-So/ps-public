// 894. All Possible Full Binary Trees
// https://leetcode.com/problems/all-possible-full-binary-trees/

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
  vector<TreeNode *> allPossibleFBT(int n) {
    vector<TreeNode *> possibleFBTs;

    if (n == 1) {
      possibleFBTs.push_back(new TreeNode());
      return possibleFBTs;
    } else if (n == 2) {
      return possibleFBTs;
    }

    for (int i = 1; i < n - 1; i++) {
      int leftNodeCount = i, rightNodeCount = n - 1 - i;
      vector<TreeNode *> leftTrees = allPossibleFBT(leftNodeCount),
                         rightTrees = allPossibleFBT(rightNodeCount);

      if (leftTrees.size() != 0 && rightTrees.size() != 0) {
        for (TreeNode *leftTree : leftTrees) {
          for (TreeNode *rightTree : rightTrees) {
            TreeNode *root = new TreeNode();
            root->left = leftTree;
            root->right = rightTree;
            possibleFBTs.push_back(root);
          }
        }
      }
    }

    return possibleFBTs;
  }
};

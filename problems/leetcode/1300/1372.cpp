// 1372. Longest ZigZag Path in a Binary Tree
// https://leetcode.com/problems/longest-zigzag-path-in-a-binary-tree/description/

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
  pair<int, int> longestZigZagWithDirection(TreeNode *node, int &maxLen) {
    pair<int, int> lens({0, 0});

    if (node->left) {
      pair<int, int> left = longestZigZagWithDirection(node->left, maxLen);
      lens.first = left.second + 1;
    }
    if (node->right) {
      pair<int, int> right = longestZigZagWithDirection(node->right, maxLen);
      lens.second = right.first + 1;
    }
    maxLen = max({maxLen, lens.first, lens.second});

    return lens;
  }

  int longestZigZag(TreeNode *root) {
    int maxLen = 0;
    longestZigZagWithDirection(root, maxLen);
    return maxLen;
  }
};

// 106. Construct Binary Tree from Inorder and Postorder Traversal
// https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/description/

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
  TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
    return buildTreeWithRange(inorder, postorder, 0, inorder.size(), 0,
                              postorder.size());
  }

  TreeNode *buildTreeWithRange(vector<int> &inorder, vector<int> &postorder,
                               int inStart, int inEnd, int outStart,
                               int outEnd) {
    if (inStart >= inEnd) {
      return nullptr;
    }

    int val = postorder[outEnd - 1];
    TreeNode *root = new TreeNode(val);

    int inRootIndex =
        find(inorder.begin() + inStart, inorder.begin() + inEnd, val) -
        inorder.begin();
    int leftLength = inRootIndex - inStart;

    root->left = buildTreeWithRange(inorder, postorder, inStart, inRootIndex,
                                    outStart, outStart + leftLength);
    root->right = buildTreeWithRange(inorder, postorder, inRootIndex + 1, inEnd,
                                     outStart + leftLength, outEnd - 1);

    return root;
  }
};

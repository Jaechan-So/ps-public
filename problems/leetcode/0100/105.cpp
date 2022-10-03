// 105. Construct Binary Tree from Preorder and Inorder Traversal
// https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/

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
  TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
    int n = preorder.size();
    return generate(preorder, inorder, pair<int, int>(0, n - 1),
                    pair<int, int>(0, n - 1));
  }
  TreeNode *generate(vector<int> &preorder, vector<int> &inorder,
                     pair<int, int> preorder_pair,
                     pair<int, int> inorder_pair) {
    if (preorder_pair.first > preorder_pair.second) {
      return nullptr;
    }
    TreeNode *root = new TreeNode(preorder[preorder_pair.first]);

    int mid =
        find(inorder.begin(), inorder.end(), preorder[preorder_pair.first]) -
        inorder.begin();
    TreeNode *left =
        generate(preorder, inorder,
                 pair<int, int>(preorder_pair.first + 1,
                                preorder_pair.first + mid - inorder_pair.first),
                 pair<int, int>(inorder_pair.first, mid - 1));
    TreeNode *right = generate(
        preorder, inorder,
        pair<int, int>(preorder_pair.first + mid - inorder_pair.first + 1,
                       preorder_pair.second),
        pair<int, int>(mid + 1, inorder_pair.second));

    root->left = left;
    root->right = right;

    return root;
  }
};

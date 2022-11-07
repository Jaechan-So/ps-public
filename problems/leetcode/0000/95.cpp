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
  vector<TreeNode *> generateTrees(int n) {
    vector<TreeNode *> nodes;
    for (int i = 1; i <= n; i++) {
      nodes.push_back(new TreeNode(i));
    }

    return generateTreesByNumbers(nodes);
  }

  vector<TreeNode *> generateTreesByNumbers(vector<TreeNode *> &nodes) {
    vector<TreeNode *> generatedTrees;

    if (nodes.empty()) {
      generatedTrees.push_back(nullptr);
      return generatedTrees;
    }

    for (int i = 0; i < nodes.size(); i++) {
      vector<TreeNode *> leftSideNodes(nodes.begin(), nodes.begin() + i);
      vector<TreeNode *> rightSideNodes(nodes.begin() + i + 1, nodes.end());

      vector<TreeNode *> generatedLeftSide =
          generateTreesByNumbers(leftSideNodes);
      vector<TreeNode *> generatedRightSide =
          generateTreesByNumbers(rightSideNodes);

      for (TreeNode *leftNode : generatedLeftSide) {
        for (TreeNode *rightNode : generatedRightSide) {
          TreeNode *root = new TreeNode(nodes[i]->val, copyNode(leftNode),
                                        copyNode(rightNode));
          generatedTrees.push_back(root);
        }
      }
    }

    return generatedTrees;
  }

  TreeNode *copyNode(TreeNode *node) {
    if (!node) {
      return nullptr;
    }

    TreeNode *copiedNode = new TreeNode(node->val);
    TreeNode *copiedLeft = nullptr, *copiedRight = nullptr;
    if (node->left) {
      copiedLeft = copyNode(node->left);
    }
    if (node->right) {
      copiedRight = copyNode(node->right);
    }

    copiedNode->left = copiedLeft;
    copiedNode->right = copiedRight;

    return copiedNode;
  }
};

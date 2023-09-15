// 863. All Nodes Distance K in Binary Tree
// https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/description/

using namespace std;

#include <vector>

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
  vector<int> kNodes;

  void traverseDownward(TreeNode *node, int k) {
    if (k == 0) {
      kNodes.push_back(node->val);
      return;
    }

    if (node->left) {
      traverseDownward(node->left, k - 1);
    }
    if (node->right) {
      traverseDownward(node->right, k - 1);
    }
  }

  int traverseUpward(TreeNode *node, TreeNode *target, int k) {
    if (node == target) {
      return k - 1;
    }

    int leftResult = -1, rightResult = -1;
    if (node->left) {
      leftResult = traverseUpward(node->left, target, k);
      if (leftResult == 0) {
        kNodes.push_back(node->val);
      }
      if (node->right && leftResult > 0) {
        traverseDownward(node->right, leftResult - 1);
      }
    }

    if (node->right) {
      rightResult = traverseUpward(node->right, target, k);
      if (rightResult == 0) {
        kNodes.push_back(node->val);
      }
      if (node->left && rightResult > 0) {
        traverseDownward(node->left, rightResult - 1);
      }
    }

    return leftResult > 0    ? leftResult - 1
           : rightResult > 0 ? rightResult - 1
                             : -1;
  }

  vector<int> distanceK(TreeNode *root, TreeNode *target, int k) {
    traverseDownward(target, k);
    traverseUpward(root, target, k);
    return kNodes;
  }
};

// 1. target보다 아래에 있는 node -> 그냥 dfs로 찾는다.
// 2. target보다 위에 있는 node -> k를 조작해서 찾는다. 이 때, target으로부터
// 올라온 방향의 길은 쓰면 안 된다.

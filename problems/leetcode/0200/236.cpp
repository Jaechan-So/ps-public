// 236. Lowest Common Ancestor of a Binary Tree
// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/

using namespace std;

#include <map>
#include <queue>

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
  TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
    // 1. Using BFS, get all parent mapping for each node.
    map<int, TreeNode *> parents;

    queue<TreeNode *> nodeQueue;
    nodeQueue.push(root);
    parents[root->val] = root;

    while (!nodeQueue.empty()) {
      TreeNode *node = nodeQueue.front();
      nodeQueue.pop();
      if (node->left) {
        parents[node->left->val] = node;
        nodeQueue.push(node->left);
      }
      if (node->right) {
        parents[node->right->val] = node;
        nodeQueue.push(node->right);
      }
    }

    // 2. Get height of given two nodes.
    int pHeight = getHeightOfNode(parents, p->val),
        qHeight = getHeightOfNode(parents, q->val);

    // 3. While two heights are different, find parent of higher(== deeper)
    // node.
    while (pHeight > qHeight) {
      p = parents[p->val];
      pHeight--;
    }
    while (pHeight < qHeight) {
      q = parents[q->val];
      qHeight--;
    }

    // 4. While two nodes are not same, find parent of each node.
    while (p != q) {
      p = parents[p->val];
      q = parents[q->val];
    }

    return p;
  }

  int getHeightOfNode(map<int, TreeNode *> &parents, int value) {
    int height = 1;
    while (value != parents[value]->val) {
      value = parents[value]->val;
      height++;
    }
    return height;
  }
};

// 865. Smallest Subtree with all the Deepest Nodes
// https://leetcode.com/problems/smallest-subtree-with-all-the-deepest-nodes/description/

using namespace std;

#include <queue>
#include <unordered_map>

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
  unordered_map<int, TreeNode *> parent;
  queue<pair<TreeNode *, int>> deepest;
  int maxHeight = 0;

  void findParentAndDeepestNodes(TreeNode *node, int height) {
    if (height > maxHeight) {
      while (!deepest.empty()) {
        deepest.pop();
      }
      maxHeight = height;
    }
    if (height == maxHeight) {
      deepest.push({node, height});
    }

    if (node->left) {
      findParentAndDeepestNodes(node->left, height + 1);
      parent[node->left->val] = node;
    }
    if (node->right) {
      findParentAndDeepestNodes(node->right, height + 1);
      parent[node->right->val] = node;
    }
  }

  TreeNode *subtreeWithAllDeepest(TreeNode *root) {
    findParentAndDeepestNodes(root, 1);

    while (deepest.size() > 1) {
      TreeNode *node1 = deepest.front().first;
      int height1 = deepest.front().second;
      deepest.pop();
      TreeNode *node2 = deepest.front().first;
      int height2 = deepest.front().second;
      deepest.pop();

      while (height1 != height2) {
        if (height1 > height2) {
          node1 = parent[node1->val];
          height1--;
        } else {
          node2 = parent[node2->val];
          height2--;
        }
      }
      while (node1 != node2) {
        node1 = parent[node1->val];
        node2 = parent[node2->val];
        height1--;
        height2--;
      }
      deepest.push({node1, height1});
    }

    return deepest.front().first;
  }
};

// 모든 Deepest Node의 LCA를 찾아야 함

// 1. Naive
// 각 Node에 대한 Parent를 찾을 수 있도록 한다.
// Deepest Node를 모두 찾는다.
// Deepest Node들의 parent가 같아질 때 까지, 계속 Parent로 움직인다. 높이가
// 같으므로 이렇게 해도 무방. 이 때 계속되는 비교로 시간 복잡도가 커지는 것을
// 막기 위해서, Divide and Conquer로 접근하면 된다.

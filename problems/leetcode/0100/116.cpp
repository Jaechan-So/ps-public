// 116. Populating Next Right Pointers in Each Node
// https://leetcode.com/problems/populating-next-right-pointers-in-each-node/

// Definition for a Node.
class Node {
public:
  int val;
  Node *left;
  Node *right;
  Node *next;

  Node() : val(0), left(nullptr), right(nullptr), next(nullptr) {}

  Node(int _val) : val(_val), left(nullptr), right(nullptr), next(nullptr) {}

  Node(int _val, Node *_left, Node *_right, Node *_next)
      : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {
public:
  Node *connect(Node *root) {
    if (root && root->left && root->right) {
      root->left->next = root->right;
      if (root->next) {
        root->right->next = root->next->left;
      } else {
        root->right->next = nullptr;
      }
      connect(root->left);
      connect(root->right);
    }
    return root;
  }
};

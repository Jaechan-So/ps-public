// 117. Populating Next Right Pointers in Each Node II
// https://leetcode.com/problems/populating-next-right-pointers-in-each-node-ii/

#include <queue>

using namespace std;

// Definition for a Node.
class Node {
public:
  int val;
  Node *left;
  Node *right;
  Node *next;

  Node() : val(0), left(NULL), right(NULL), next(NULL) {}

  Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

  Node(int _val, Node *_left, Node *_right, Node *_next)
      : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {
private:
  Node *root;
  queue<pair<Node *, int>> nodesWithHeight;
  Node *prevNode;
  int prevHeight;

  void setRootNode(Node *_root) { root = _root; }

  void initWithRootNode() {
    initNodeQueue();
    initPrev();
  }

  void initNodeQueue() {
    if (root == nullptr) {
      return;
    }
    if (root->left != nullptr) {
      nodesWithHeight.push(make_pair(root->left, 2));
    }
    if (root->right != nullptr) {
      nodesWithHeight.push(make_pair(root->right, 2));
    }
  }

  void initPrev() {
    prevNode = root;
    prevHeight = 1;
  }

  void next() {
    Node *currentNode = nodesWithHeight.front().first;
    int currentHeight = nodesWithHeight.front().second;
    nodesWithHeight.pop();

    if (prevHeight == currentHeight) {
      prevNode->next = currentNode;
    }

    if (currentNode->left != nullptr) {
      nodesWithHeight.push(make_pair(currentNode->left, currentHeight + 1));
    }
    if (currentNode->right != nullptr) {
      nodesWithHeight.push(make_pair(currentNode->right, currentHeight + 1));
    }

    prevNode = currentNode;
    prevHeight = currentHeight;
  }

public:
  Node *connect(Node *root) {
    setRootNode(root);
    initWithRootNode();

    while (!nodesWithHeight.empty()) {
      next();
    }

    return root;
  }
};

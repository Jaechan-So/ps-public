// 1650. Lowest Common Ancestor of a Binary Tree III
// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree-iii/

// Definition for a Node.
class Node {
public:
  int val;
  Node *left;
  Node *right;
  Node *parent;
};

class Solution {
public:
  Node *lowestCommonAncestor(Node *p, Node *q) {
    Node *startFromP = p;
    int heightOfP = 0;
    while (startFromP) {
      startFromP = startFromP->parent;
      heightOfP++;
    }

    Node *startFromQ = q;
    int heightOfQ = 0;
    while (startFromQ) {
      startFromQ = startFromQ->parent;
      heightOfQ++;
    }

    while (heightOfP > heightOfQ) {
      p = p->parent;
      heightOfP--;
    }

    while (heightOfQ > heightOfP) {
      q = q->parent;
      heightOfQ--;
    }

    while (p != q) {
      p = p->parent;
      q = q->parent;
    }

    return p;
  }
};

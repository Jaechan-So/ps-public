// 430. Flatten a Multilevel Doubly Linked List
// https://leetcode.com/problems/flatten-a-multilevel-doubly-linked-list/

using namespace std;

#include <utility>

class Node {
public:
  int val;
  Node *prev;
  Node *next;
  Node *child;
};

class Solution {
public:
  Node *flatten(Node *head) {
    flattenAndReturnSide(head);
    return head;
  }

  pair<Node *, Node *> flattenAndReturnSide(Node *head) {
    Node *curr = head, *tail = nullptr;

    while (curr) {
      if (curr->child) {
        pair<Node *, Node *> flattenedNodeSide =
            flattenAndReturnSide(curr->child);
        Node *flattenedHead = flattenedNodeSide.first,
             *flattenedTail = flattenedNodeSide.second,
             *originalNext = curr->next;

        curr->next = flattenedHead;
        flattenedHead->prev = curr;

        flattenedTail->next = originalNext;
        if (originalNext) {
          originalNext->prev = flattenedTail;
        }

        if (originalNext == nullptr) {
          tail = flattenedTail;
        }
        curr->child = nullptr;
        curr = originalNext;
      } else {
        if (curr->next == nullptr) {
          tail = curr;
        }
        curr = curr->next;
      }
    }

    return {head, tail};
  }
};

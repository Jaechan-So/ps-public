// 237. Delete Node in a Linked List
// https://leetcode.com/problems/delete-node-in-a-linked-list/

using namespace std;

#include <utility>

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
  void deleteNode(ListNode *node) {
    while (node->next->next) {
      node->val = node->next->val;
      node = node->next;
    }
    node->val = node->next->val;
    node->next = nullptr;
  }
};

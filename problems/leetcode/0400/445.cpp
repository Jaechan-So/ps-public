// 445. Add Two Numbers II
// https://leetcode.com/problems/add-two-numbers-ii/description/

using namespace std;

#include <utility>

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
  ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
    pair<ListNode *, int> r1 = reverseList(l1), r2 = reverseList(l2);

    ListNode *node1 = r1.first, *node2 = r2.first,
             *saveNode = r1.second >= r2.second ? r1.first : r2.first,
             *originalSaveNode = saveNode;

    int carry = 0;
    while (node1 || node2) {
      int sum = (node1 ? node1->val : 0) + (node2 ? node2->val : 0) + carry;
      carry = sum >= 10 ? 1 : 0;
      saveNode->val = sum % 10;

      node1 = node1 ? node1->next : node1;
      node2 = node2 ? node2->next : node2;

      if (!node1 && !node2 && carry > 0) {
        ListNode *lastNode = new ListNode(carry);
        saveNode->next = lastNode;
        return reverseList(originalSaveNode).first;
      }

      if (!node1 && !node2 && carry == 0) {
        return reverseList(originalSaveNode).first;
      }

      saveNode = saveNode ? saveNode->next : saveNode;
    }

    return nullptr;
  }

  pair<ListNode *, int> reverseList(ListNode *node) {
    ListNode *prevNode = nullptr;
    int length = 0;

    while (node) {
      ListNode *currNode = node;
      node = node->next;
      currNode->next = prevNode;
      prevNode = currNode;
      length++;
    }

    return {prevNode, length};
  }
};

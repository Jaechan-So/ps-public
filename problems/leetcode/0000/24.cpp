// 24. Swap Nodes in Pairs
// https://leetcode.com/problems/swap-nodes-in-pairs/description/

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
  ListNode *swapPairs(ListNode *head) {
    if (!head || !head->next) {
      return head;
    }

    ListNode *firstNode = head->next, *secondNode = head,
             *thirdNode = swapPairs(head->next->next);
    firstNode->next = secondNode;
    secondNode->next = thirdNode;
    return firstNode;
  }
};

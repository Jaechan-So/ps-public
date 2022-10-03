// 160. Intersection of Two Linked Lists
// https://leetcode.com/problems/intersection-of-two-linked-lists/

using namespace std;

#include <stack>

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
  ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    stack<ListNode *> stackA;
    stack<ListNode *> stackB;
    ListNode *intersectNode = nullptr;

    while (headA) {
      stackA.push(headA);
      headA = headA->next;
    }
    while (headB) {
      stackB.push(headB);
      headB = headB->next;
    }

    while (!stackA.empty() && !stackB.empty()) {
      ListNode *tailA = stackA.top();
      stackA.pop();

      ListNode *tailB = stackB.top();
      stackB.pop();

      if (tailA == tailB) {
        intersectNode = tailA;
      } else {
        break;
      }
    }

    return intersectNode;
  }
};

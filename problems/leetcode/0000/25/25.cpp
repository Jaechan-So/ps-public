// 25. Reverse Nodes in k-Group
// https://leetcode.com/problems/reverse-nodes-in-k-group/

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
  ListNode *reverseKGroup(ListNode *head, int k) {
    if (!head) {
      return nullptr;
    }

    pair<ListNode *, bool> nextGroupHeadAndIsElementShortage =
        getNextGroupHead(head, k);
    ListNode *nextGroupHead = nextGroupHeadAndIsElementShortage.first;
    bool isElementShortage = nextGroupHeadAndIsElementShortage.second;
    if (isElementShortage) {
      return head;
    }

    ListNode *reversedNextGroupHead = reverseKGroup(nextGroupHead, k);

    ListNode *targetNext = reversedNextGroupHead, *target = head;
    for (int i = 0; i < k; i++) {
      ListNode *nextTarget = target->next;
      target->next = targetNext;
      targetNext = target;
      target = nextTarget;
    }

    return targetNext;
  }

  pair<ListNode *, bool> getNextGroupHead(ListNode *head, int k) {
    ListNode *nextGroupHead = head;
    int count = 0;

    while (nextGroupHead && count < k) {
      nextGroupHead = nextGroupHead->next;
      count++;
    }

    return {nextGroupHead, count < k};
  }
};

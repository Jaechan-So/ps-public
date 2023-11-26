// 23. Merge k Sorted Lists
// https://leetcode.com/problems/merge-k-sorted-lists/

using namespace std;

#include <queue>
#include <vector>

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
  struct cmp {
    bool operator()(ListNode *n1, ListNode *n2) { return n1->val > n2->val; }
  };
  ListNode *mergeKLists(vector<ListNode *> &lists) {
    ListNode *head = nullptr;
    priority_queue<ListNode *, vector<ListNode *>, cmp> pq;

    for (vector<ListNode *>::iterator iter = lists.begin(); iter != lists.end();
         iter++) {
      ListNode *list_head = *iter;
      for (ListNode *cur = list_head; cur != nullptr; cur = cur->next) {
        pq.push(cur);
      }
    }

    while (!pq.empty()) {
      ListNode *cur = pq.top();
      pq.pop();
      if (head == nullptr) {
        head = cur;
      }
      if (!pq.empty()) {
        cur->next = pq.top();
      } else {
        cur->next = nullptr;
      }
    }

    return head;
  }
};

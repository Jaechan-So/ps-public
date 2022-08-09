// 148. Sort List
// https://leetcode.com/problems/sort-list/

using namespace std;

#include <queue>

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
    bool operator()(ListNode *l1, ListNode *l2) { return l1->val > l2->val; }
  };
  ListNode *sortList(ListNode *head) {
    priority_queue<ListNode *, vector<ListNode *>, cmp> pq;
    ListNode *cur = head;
    while (cur) {
      pq.push(cur);
      cur = cur->next;
    }

    ListNode *new_head = nullptr;
    if (!pq.empty()) {
      new_head = pq.top();
      pq.pop();
      ListNode *prev = new_head;
      while (!pq.empty()) {
        ListNode *cur = pq.top();
        pq.pop();
        prev->next = cur;
        if (pq.empty()) {
          cur->next = nullptr;
        }
        prev = cur;
      }
    }

    return new_head;
  }
};

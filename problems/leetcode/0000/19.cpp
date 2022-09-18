// 19. Remove Nth Node From End of List
// https://leetcode.com/problems/remove-nth-node-from-end-of-list/

using namespace std;

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
  ListNode *removeNthFromEnd(ListNode *head, int n) {
    if (!(head->next)) {
      return nullptr;
    }
    vector<ListNode *> nodes;
    ListNode *curr = head;

    while (curr) {
      nodes.push_back(curr);
      curr = curr->next;
    }

    int target = nodes.size() - n;
    if (target > 0) {
      nodes[target - 1]->next = nodes[target]->next;
      return head;
    }
    return nodes[1];
  }
};

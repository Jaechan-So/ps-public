// 1171. Remove Zero Sum Consecutive Nodes from Linked List
// https://leetcode.com/problems/remove-zero-sum-consecutive-nodes-from-linked-list/

using namespace std;

#include <map>

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
  ListNode *removeZeroSumSublists(ListNode *head) {
    map<int, ListNode *> prefixSumToNode;

    ListNode *currNode = head;
    int sum = 0;
    while (currNode) {
      sum += currNode->val;

      if (sum == 0) {
        ListNode *history = head;
        head = currNode->next;

        int historySum = 0;
        while (history != currNode->next) {
          historySum += history->val;
          prefixSumToNode.erase(historySum);
          history = history->next;
        }
      } else if (prefixSumToNode.find(sum) != prefixSumToNode.end()) {
        ListNode *prevNode = prefixSumToNode[sum];

        ListNode *history = prevNode->next;
        int historySum = sum;
        while (history != currNode) {
          historySum += history->val;
          prefixSumToNode.erase(historySum);
          history = history->next;
        }

        prevNode->next = currNode->next;
      } else {
        prefixSumToNode[sum] = currNode;
      }

      currNode = currNode->next;
    }

    return head;
  }
};

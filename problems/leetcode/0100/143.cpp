// 143. Reorder List
// https://leetcode.com/problems/reorder-list/

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
  void reorderList(ListNode *head) {
    vector<ListNode *> reverseNodes;

    ListNode *singleJump = head, *doubleJump = head;
    while (doubleJump->next != nullptr) {
      if (singleJump->next != nullptr) {
        singleJump = singleJump->next;
      }
      if (doubleJump->next != nullptr) {
        doubleJump = doubleJump->next;
      }
      if (doubleJump->next != nullptr) {
        doubleJump = doubleJump->next;
      }
    }

    while (singleJump->next != nullptr) {
      reverseNodes.push_back(singleJump->next);
      ListNode *previousNode = singleJump;
      singleJump = singleJump->next;
      previousNode->next = nullptr;
    }

    ListNode *traverseNode = head;
    while (!reverseNodes.empty()) {
      ListNode *nextNode = traverseNode->next,
               *reverseNode = reverseNodes.back();
      if (traverseNode == reverseNode) {
        traverseNode->next = nullptr;
        break;
      }
      traverseNode->next = reverseNode;
      reverseNode->next = nextNode;
      traverseNode = nextNode;
      reverseNodes.pop_back();
    }
  }
};

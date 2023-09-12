// 1019. Next Greater Node In Linked List
// https://leetcode.com/problems/next-greater-node-in-linked-list/description/

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
  vector<int> nextLargerNodes(ListNode *head) {
    vector<pair<int, int>> nodes;
    nodes.push_back({-1, INT_MAX}); // (index, val)

    ListNode *node = head;
    int n = 0;
    while (node) {
      n++;
      node = node->next;
    }
    vector<int> answer(n, 0);

    node = head;
    int index = 0;
    while (node) {
      while (nodes.back().second < node->val) {
        answer[nodes.back().first] = node->val;
        nodes.pop_back();
      }
      nodes.push_back({index, node->val});

      node = node->next;
      index++;
    }

    return answer;
  }
};

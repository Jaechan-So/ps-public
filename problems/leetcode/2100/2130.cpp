// 2130. Maximum Twin Sum of a Linked List
// https://leetcode.com/problems/maximum-twin-sum-of-a-linked-list/

using namespace std;

#include <algorithm>
#include <vector>

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// TODO: Improve with two pointer

class Solution {
public:
  int pairSum(ListNode *head) {
    vector<int> values;
    ListNode *current = head;
    while (current != nullptr) {
      values.push_back(current->val);
      current = current->next;
    }

    int answer = 0;
    int length = values.size();
    for (int i = 0; i < length / 2; i++) {
      answer = max(answer, values[i] + values[length - 1 - i]);
    }

    return answer;
  }
};

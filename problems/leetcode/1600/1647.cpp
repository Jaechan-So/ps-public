// 1647. Minimum Deletions to Make Character Frequencies Unique
// https://leetcode.com/problems/minimum-deletions-to-make-character-frequencies-unique/

using namespace std;

#include <queue>
#include <string>
#include <unordered_map>

class Solution {
public:
  int minDeletions(string s) {
    int answer = 0;

    unordered_map<char, int> charCount;
    for (auto &ch : s) {
      charCount[ch]++;
    }

    priority_queue<int, vector<int>, greater<int>> counts;
    for (auto &p : charCount) {
      int count = p.second;
      counts.push(count);
    }

    priority_queue<int, vector<int>, less<int>> remainingSlots;
    int prev = 0;
    while (!counts.empty()) {
      int count = counts.top();
      counts.pop();

      if (prev == count) {
        if (remainingSlots.empty()) {
          answer += count;
        } else {
          int slot = remainingSlots.top();
          remainingSlots.pop();

          answer += (count - slot);
        }
      } else {
        for (int i = prev + 1; i < count; i++) {
          remainingSlots.push(i);
        }
      }

      prev = count;
    }

    return answer;
  }
};

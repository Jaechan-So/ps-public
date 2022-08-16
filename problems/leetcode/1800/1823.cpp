// 1823. Find the Winner of the Circular Game
// https://leetcode.com/problems/find-the-winner-of-the-circular-game/

using namespace std;

#include <vector>

class Solution {
public:
  int findTheWinner(int n, int k) {
    vector<int> friends;
    for (int i = 1; i <= n; i++) {
      friends.push_back(i);
    }

    int i = 0;
    while (friends.size() > 1) {
      i += k - 1;
      while (i >= friends.size()) {
        i -= friends.size();
      }
      friends.erase(friends.begin() + i);
    }

    return friends[0];
  }
};

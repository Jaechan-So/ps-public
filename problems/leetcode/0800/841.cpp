// 841. Keys and Rooms
// https://leetcode.com/problems/keys-and-rooms/description/

using namespace std;

#include <set>
#include <vector>

class Solution {
public:
  bool canVisitAllRooms(vector<vector<int>> &rooms) {
    set<int> visited, notVisitedButUnlocked;
    visited.insert(0);
    for (int i = 0; i < rooms[0].size(); i++) {
      notVisitedButUnlocked.insert(rooms[0][i]);
    }

    while (!notVisitedButUnlocked.empty()) {
      int roomNum = *notVisitedButUnlocked.begin();
      for (int i = 0; i < rooms[roomNum].size(); i++) {
        if (visited.find(rooms[roomNum][i]) == visited.end()) {
          notVisitedButUnlocked.insert(rooms[roomNum][i]);
        }
      }
      notVisitedButUnlocked.erase(roomNum);
      visited.insert(roomNum);
    }

    return visited.size() == rooms.size();
  }
};

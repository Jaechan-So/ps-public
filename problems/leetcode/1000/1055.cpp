// 1055. Shortest Way to Form String
// https://leetcode.com/problems/shortest-way-to-form-string/

using namespace std;

#include <string>
#include <vector>

class Solution {
public:
  int shortestWay(string source, string target) {
    // Create a map with every position of each alphabet.
    vector<vector<int>> positions(26, vector<int>());
    for (int i = 0; i < source.size(); i++) {
      positions[source[i] - 'a'].push_back(i);
    }

    // Find if current alphabet has a lower bound index with previous alphabet's
    // position. (by binary search)
    int currentPosition = 0, subsequenceCount = 0;
    for (auto ch : target) {
      vector<int>::iterator iter =
          lower_bound(positions[ch - 'a'].begin(), positions[ch - 'a'].end(),
                      currentPosition);
      if (iter == positions[ch - 'a'].end()) {
        if (currentPosition == 0) {
          // There is no current character in source.
          return -1;
        }

        subsequenceCount++;

        // If we did not find, create a new cycle.
        vector<int>::iterator newIter = lower_bound(
            positions[ch - 'a'].begin(), positions[ch - 'a'].end(), 0);
        if (newIter == positions[ch - 'a'].end()) {
          return -1;
        } else {
          currentPosition = *newIter + 1;
        }
      } else {
        // If we find, keep going.
        currentPosition = *iter + 1;
      }
    }

    return subsequenceCount + 1;
  }
};

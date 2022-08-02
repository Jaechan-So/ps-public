// 881. Boats to Save People
// https://leetcode.com/problems/boats-to-save-people/

using namespace std;

#include <algorithm>
#include <vector>

class Solution {
public:
  int numRescueBoats(vector<int> &people, int limit) {
    int count = people.size();

    vector<int> sortedPeople(people);
    sort(sortedPeople.begin(), sortedPeople.end());

    int light = 0, heavy = count - 1, boats = 0;
    while (light <= heavy) {
      int lightPerson = sortedPeople[light], heavyPerson = sortedPeople[heavy];

      if (lightPerson + heavyPerson > limit) {
        boats++;
        heavy--;
      } else {
        boats++;
        light++;
        heavy--;
      }
    }

    return boats;
  }
};

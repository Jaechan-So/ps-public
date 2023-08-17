// 1431. Kids With the Greatest Number of Candies
// https://leetcode.com/problems/kids-with-the-greatest-number-of-candies/description

using namespace std;

#include <utility>
#include <vector>

class Solution {
public:
  vector<bool> kidsWithCandies(vector<int> &candies, int extraCandies) {
    int maxCandies = *max_element(candies.begin(), candies.end());

    vector<bool> isGreatestWithExtra;
    for (int candy : candies) {
      isGreatestWithExtra.push_back(candy + extraCandies >= maxCandies);
    }

    return isGreatestWithExtra;
  }
};

// 1482. Minimum Number of Days to Make m Bouquets
// https://leetcode.com/problems/minimum-number-of-days-to-make-m-bouquets/description/

using namespace std;

#include <map>
#include <unordered_map>
#include <vector>

class Solution {
public:
  int minDays(vector<int> &bloomDay, int m, int k) {
    int n = bloomDay.size();
    // 1. If total required flower number is bigger than we have, then we cannot
    // make such amount of bouquets.
    if ((long long)n < (long long)m * (long long)k) {
      return -1;
    }

    // 2. Make day to index pair of bloom days.
    map<int, vector<int>> dayToIndex;
    for (int i = 0; i < n; i++) {
      if (dayToIndex.find(bloomDay[i]) != dayToIndex.end()) {
        dayToIndex[bloomDay[i]].push_back(i);
      } else {
        dayToIndex[bloomDay[i]] = vector<int>(1, i);
      }
    }

    int totalBouquets = 0;
    vector<int> adjacentHead(n, -1);
    unordered_map<int, int> adjacentFlowers;

    for (pair<int, vector<int>> p : dayToIndex) {
      int today = p.first;
      vector<int> bloomingIndicies = p.second;

      for (int i = 0; i < bloomingIndicies.size(); i++) {
        // 3. We have to know how many bouquets are current, how long after
        // composite adjacencies, and what is a head index after composition.
        int bloomingIndex = bloomingIndicies[i], currentBouquets = 0,
            compositeLength = 1, compositeHead = bloomingIndex;

        // 4. For left adjacent index, compositeHead must be set by left most
        // head if exists.
        if (bloomingIndex > 0) {
          int leftHead = getHeadIndex(adjacentHead, bloomingIndex - 1);
          if (leftHead != -1) {
            compositeLength += adjacentFlowers[leftHead];
            currentBouquets += adjacentFlowers[leftHead] / k;
            compositeHead = leftHead;
          }
        }

        // 5. For right adjacent index, we have to composite right adjacencies
        // with current index.
        if (bloomingIndex < n - 1) {
          int rightHead = adjacentHead[bloomingIndex + 1];
          if (rightHead != -1) {
            compositeLength += adjacentFlowers[rightHead];
            currentBouquets += adjacentFlowers[rightHead] / k;
            adjacentFlowers.erase(rightHead);
            adjacentHead[bloomingIndex + 1] = compositeHead;
          }
        }

        adjacentFlowers[compositeHead] = compositeLength;
        adjacentHead[bloomingIndex] = compositeHead;
        totalBouquets += ((compositeLength / k) - currentBouquets);
      }

      if (m <= totalBouquets) {
        return today;
      }
    }

    return -1;
  }

  // Similar implementation with union find.
  int getHeadIndex(vector<int> &adjacentHead, int i) {
    if (adjacentHead[i] == -1) {
      return -1;
    }

    int headIndex = i;
    while (adjacentHead[headIndex] != headIndex) {
      headIndex = adjacentHead[headIndex];
    }

    return headIndex;
  }
};

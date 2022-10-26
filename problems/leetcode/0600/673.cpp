// 673. Number of Longest Increasing Subsequence
// https://leetcode.com/problems/number-of-longest-increasing-subsequence/

// Testcases

// [1,3,5,4,7]
// [2,2,2,2,2]
// [1,3,5,4,7,8,8]
// [1,2,4,3,5,4,7,2,5]
// [1,4,5,3,4]
// [1,7,1,8,2,3]
// [1,10,14,16,2,11,15]

using namespace std;

#include <map>
#include <vector>

class Solution {
public:
  int findNumberOfLIS(vector<int> &nums) {
    vector<int> advantages;
    vector<multimap<int, int>> numberOfCases;

    for (auto num : nums) {
      // Find the lower bound location of the number with respect to current
      // advantage snapshot. Here 'advantage snapshot' means that we always
      // store most advantageous sequence. Recall how do you construct the
      // O(nlogn) LIS solution.
      vector<int>::iterator iter =
          lower_bound(advantages.begin(), advantages.end(), num);

      if (iter == advantages.end()) {
        // If the incoming number is the largest number, then we have to
        // consider how many cases of previous LIS.
        int cases = 0;
        if (!numberOfCases.empty()) {
          // In current number of cases, all of the elements have smaller index
          // then current number. So if the element exists in numberOfCases,
          // then there exists some path which ends with the element.
          for (multimap<int, int>::iterator caseIter =
                   numberOfCases.back().begin();
               caseIter != numberOfCases.back().end() && caseIter->first < num;
               caseIter++) {
            cases += caseIter->second;
          }
        } else {
          cases = 1;
        }

        multimap<int, int> newCases;
        newCases.insert({num, cases});
        numberOfCases.push_back(multimap<int, int>(newCases));

        advantages.push_back(num);
      } else {
        // If the incoming number is not the largest number, then we have to
        // record it as middle case.
        int index = iter - advantages.begin();
        if (index != 0) {
          int cases = 0;
          for (multimap<int, int>::iterator caseIter =
                   numberOfCases[index - 1].begin();
               caseIter != numberOfCases[index - 1].end() &&
               caseIter->first < num;
               caseIter++) {
            cases += caseIter->second;
          }
          numberOfCases[index].insert({num, cases});
        } else {
          numberOfCases[0].insert({num, 1});
        }

        *iter = num;
      }
    }

    int answer = 0;
    for (auto cases : numberOfCases.back()) {
      answer += cases.second;
    }

    return answer;
  }
};

// Notes

// 1,[2,2],[4,3],[5,4],[7,5] -> 4,5,7 / 3,5,7 / 3,4,7 / 3,5,5 -> 1, 1 / 2, 1 /
// 3, 1 1,2,3,4,5

// 1,[4,3],5
// [1,1],[7,2],[8,3]

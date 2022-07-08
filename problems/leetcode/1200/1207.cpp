// 1207. Unique Number of Occurrences
// https://leetcode.com/problems/unique-number-of-occurrences/

using namespace std;

#include <vector>
#include <map>
#include <set>

class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        map<int, int> numCounts;

        for(auto& elem: arr) {
            numCounts[elem]++;
        }

        set<int> counts;
        for(auto& pair: numCounts) {
            counts.insert(pair.second);
        }

        return numCounts.size() == counts.size();
    }
};

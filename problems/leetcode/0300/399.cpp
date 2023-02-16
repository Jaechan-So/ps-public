// 399. Evaluate Division
// https://leetcode.com/problems/evaluate-division/description/

using namespace std;

#include <map>
#include <set>
#include <string>
#include <vector>

class Solution {
public:
  vector<double> calcEquation(vector<vector<string>> &equations,
                              vector<double> &values,
                              vector<vector<string>> &queries) {
    map<string, map<string, double>> startEndDistance;

    for (int i = 0; i < equations.size(); i++) {
      string &start = equations[i][0], end = equations[i][1];
      double distance = values[i];

      startEndDistance[start][end] = distance;
      startEndDistance[end][start] = 1 / distance;
    }

    set<string> visitedVariables;
    vector<double> calculatedValues;

    for (vector<string> &query : queries) {
      string &start = query[0], end = query[1];

      pair<bool, double> result =
          getQueryValue(startEndDistance, visitedVariables, start, end, 1.0);
      visitedVariables.clear();
      bool isValid = result.first;
      double value = result.second;

      calculatedValues.push_back(isValid ? value : -1.0);
    }

    return calculatedValues;
  }

  pair<bool, double>
  getQueryValue(map<string, map<string, double>> &startEndDistance,
                set<string> &visitedVariables, string &start, string &end,
                double currentValue) {
    if (startEndDistance.find(start) == startEndDistance.end()) {
      return {false, -1.0};
    }

    if (start == end) {
      return {true, currentValue};
    }

    visitedVariables.insert(start);

    for (map<string, double>::iterator iter = startEndDistance[start].begin();
         iter != startEndDistance[start].end(); iter++) {
      string nextStart = iter->first;
      double multiplier = iter->second;

      if (visitedVariables.find(nextStart) == visitedVariables.end()) {
        pair<bool, double> result =
            getQueryValue(startEndDistance, visitedVariables, nextStart, end,
                          currentValue * multiplier);

        bool isValid = result.first;
        if (isValid) {
          return result;
        }
      }
    }

    return {false, -1.0};
  }
};

// 726. Number of Atoms
// https://leetcode.com/problems/number-of-atoms/description/

using namespace std;

#include <map>
#include <string>

class Solution {
public:
  string countOfAtoms(string formula) {
    int index = 0;
    map<string, int> countOfElements;

    while (index < formula.size()) {
      map<string, int> currentCounts = getCountsOfElements(formula, index);
      for (map<string, int>::iterator iter = currentCounts.begin();
           iter != currentCounts.end(); iter++) {
        countOfElements[iter->first] += iter->second;
      }
    }

    string counts;
    for (map<string, int>::iterator iter = countOfElements.begin();
         iter != countOfElements.end(); iter++) {
      counts += iter->first;
      if (iter->second > 1) {
        counts += to_string(iter->second);
      }
    }

    return counts;
  }

  map<string, int> getCountsOfElements(string &formula, int &index) {
    map<string, int> countByName;

    if (isalpha(formula[index])) {
      int elementNameIndex = index, elementCountIndex = index + 1;
      while (elementCountIndex < formula.size() &&
             islower(formula[elementCountIndex])) {
        elementCountIndex++;
      }
      int elementCountEndIndex = elementCountIndex;
      while (elementCountEndIndex < formula.size() &&
             isdigit(formula[elementCountEndIndex])) {
        elementCountEndIndex++;
      }
      string elementName(formula.begin() + elementNameIndex,
                         formula.begin() + elementCountIndex);
      int elementCount =
          elementCountIndex == elementCountEndIndex
              ? 1
              : stoi(string(formula.begin() + elementCountIndex,
                            formula.begin() + elementCountEndIndex));
      countByName[elementName] = elementCount;
      index = elementCountEndIndex;
    } else {
      if (formula[index] == '(') {
        index++;
        while (formula[index] != ')') {
          map<string, int> innerCountByName =
              getCountsOfElements(formula, index);
          for (map<string, int>::iterator iter = innerCountByName.begin();
               iter != innerCountByName.end(); iter++) {
            countByName[iter->first] += iter->second;
          }
        }
        index++;

        int elementCountIndex = index, elementCountEndIndex = index;
        while (elementCountEndIndex < formula.size() &&
               isdigit(formula[elementCountEndIndex])) {
          elementCountEndIndex++;
        }
        int elementCount =
            elementCountIndex == elementCountEndIndex
                ? 1
                : stoi(string(formula.begin() + elementCountIndex,
                              formula.begin() + elementCountEndIndex));

        for (map<string, int>::iterator iter = countByName.begin();
             iter != countByName.end(); iter++) {
          countByName[iter->first] = elementCount * (iter->second);
        }
        index = elementCountEndIndex;
      }
    }

    return countByName;
  }
};

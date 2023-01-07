// 6287. Categorize Box According to Criteria
// https://leetcode.com/contest/biweekly-contest-95/problems/categorize-box-according-to-criteria/
// Result: Accepted

using namespace std;

#include <cmath>
#include <string>

class Solution {
public:
  string categorizeBox(int length, int width, int height, int mass) {
    bool bulky = isBulky(length, width, height, mass);
    bool heavy = isHeavy(mass);

    if (bulky && heavy) {
      return string("Both");
    }

    if (!bulky && !heavy) {
      return string("Neither");
    }

    return bulky ? string("Bulky") : string("Heavy");
  }

  bool isBulky(int length, int width, int height, int mass) {
    int dimensions[4] = {length, width, height, mass};
    for (int i = 0; i < 4; i++) {
      if (dimensions[i] >= pow(10, 4)) {
        return true;
      }
    }

    return (long long)length * (long long)width * (long long)height >=
           (long long)pow(10, 9);
  }

  bool isHeavy(int mass) { return mass >= 100; }
};

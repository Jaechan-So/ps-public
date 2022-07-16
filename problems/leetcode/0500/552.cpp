// 552. Student Attendance Record II
// https://leetcode.com/problems/student-attendance-record-ii/

using namespace std;

#include <vector>

class Solution {
public:
  int checkRecord(int n) {
    vector<long long> recordWithoutAbsent(n + 1, 1);
    for (int i = 1; i <= n; i++) {
      if (i == 1) {
        recordWithoutAbsent[i] = 2;
      } else if (i == 2) {
        recordWithoutAbsent[i] = 4;
      } else {
        recordWithoutAbsent[i] =
            getModuloNumber(getModuloNumber(recordWithoutAbsent[i - 3]) +
                            getModuloNumber(recordWithoutAbsent[i - 2]) +
                            getModuloNumber(recordWithoutAbsent[i - 1]));
      }
    }

    long long recordWithAbsent = 0;
    for (int i = 0; i < n; i++) {
      recordWithAbsent +=
          getModuloNumber(getModuloNumber(recordWithoutAbsent[i]) *
                          getModuloNumber(recordWithoutAbsent[n - 1 - i]));
    }

    return getModuloNumber(getModuloNumber(recordWithAbsent) +
                           getModuloNumber(recordWithoutAbsent[n]));
  }

  long long getModuloNumber(long long n) { return n % 1000000007; }
};

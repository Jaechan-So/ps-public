// 869. Reordered Power of 2
// https://leetcode.com/problems/reordered-power-of-2/description/

class Solution {
public:
  bool reorderedPowerOf2(int n) {
    int digitToCount[10] = {
        0,
    };
    int totalDigitCount = 0, num = n;

    while (num > 0) {
      int digit = num % 10;
      digitToCount[digit]++;
      totalDigitCount++;
      num /= 10;
    }

    long long sameDigitCountNum = 1;
    while (getDigitCount(sameDigitCountNum) < totalDigitCount) {
      sameDigitCountNum *= 2;
    }

    while (getDigitCount(sameDigitCountNum) == totalDigitCount) {
      int currentDigitToCount[10] = {
          0,
      };
      int currentSameDigitCountNum = sameDigitCountNum;

      while (currentSameDigitCountNum > 0) {
        int digit = currentSameDigitCountNum % 10;
        currentDigitToCount[digit]++;
        currentSameDigitCountNum /= 10;
      }

      int sameCount = 0;
      for (int i = 0; i < 10; i++) {
        if (currentDigitToCount[i] == digitToCount[i]) {
          sameCount++;
        }
      }
      if (sameCount == 10) {
        return true;
      }

      sameDigitCountNum *= 2;
    }

    return false;
  }

  int getDigitCount(long long ll) {
    int totalDigitCount = 0;

    while (ll > 0) {
      totalDigitCount++;
      ll /= 10;
    }

    return totalDigitCount;
  }
};

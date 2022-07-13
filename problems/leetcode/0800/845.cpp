// 845. Longest Mountain in Array
// https://leetcode.com/problems/longest-mountain-in-array/

using namespace std;

#include <vector>

enum Slope {
  UPHILL, FLAT, DOWNHILL
};

class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int horizontalLength = arr.size();
        if(horizontalLength < 3) {
            return 0;
        }

        Slope currentSlope = convertSlope(arr[0], arr[1]);
        bool validMountain = currentSlope == DOWNHILL ? false : true;
        int currentLength = currentSlope == UPHILL ? 2 : 0, maxLength = 0;

        for(int i = 1; i < horizontalLength - 1; i++) {
            Slope nextSlope = convertSlope(arr[i], arr[i+1]);

            if(currentSlope == UPHILL && nextSlope == UPHILL) {
                currentLength++;
            } else if(currentSlope == UPHILL && nextSlope == FLAT) {
                currentLength = 0;
            } else if(currentSlope == UPHILL && nextSlope == DOWNHILL) {
                currentLength++;
            } else if(currentSlope == FLAT && nextSlope == UPHILL) {
                currentLength = 2;
            } else if(currentSlope == FLAT && nextSlope == DOWNHILL) {
                validMountain = false;
            } else if(currentSlope == DOWNHILL && nextSlope == UPHILL) {
                maxLength = max(currentLength, maxLength);
                currentLength = 2;
                validMountain = true;
            } else if(currentSlope == DOWNHILL && nextSlope == FLAT) {
                maxLength = max(currentLength, maxLength);
                currentLength = 0;
                validMountain = true;
            } else if (currentSlope == DOWNHILL && nextSlope == DOWNHILL && validMountain) {
                currentLength++;
            }

            currentSlope = nextSlope;
        }

        return currentSlope == DOWNHILL ? max(currentLength, maxLength) : maxLength;
    }

    Slope convertSlope(int prev, int next) {
        return prev < next ? UPHILL : prev == next ? FLAT : DOWNHILL;
    }
};

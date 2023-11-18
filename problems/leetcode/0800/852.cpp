// 852. Peak Index in a Mountain Array
// https://leetcode.com/problems/peak-index-in-a-mountain-array/description/

using namespace std;

#include <vector>

class Solution {
public:
  int peakIndexInMountainArray(vector<int> &arr) {
    int n = arr.size(), start = 0, end = n - 1;

    while (end - start + 1 >= 3) {
      int mid = (start + end) / 2;

      if (arr[mid - 1] < arr[mid] && arr[mid] < arr[mid + 1]) {
        start = mid;
      } else if (arr[mid - 1] > arr[mid] && arr[mid] > arr[mid + 1]) {
        end = mid;
      } else {
        return mid;
      }
    }

    return -1;
  }
};

// 4. Median of Two Sorted Arrays
// https://leetcode.com/problems/median-of-two-sorted-arrays/description/

using namespace std;

#include <vector>

class Solution {
public:
  double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
    int n1 = nums1.size(), n2 = nums2.size();
    vector<int> &smallerNums = n1 <= n2 ? nums1 : nums2,
                biggerNums = n1 <= n2 ? nums2 : nums1;
    int ns = smallerNums.size(), nb = biggerNums.size(), start = 0, end = ns;
    while (start <= end) {
      int pivotS = (start + end) / 2, pivotB = ((ns + nb + 1) / 2) - pivotS;

      int leftBoundaryS = pivotS == 0 ? INT_MIN : smallerNums[pivotS - 1];
      int rightBoundaryS = pivotS == ns ? INT_MAX : smallerNums[pivotS];
      int leftBoundaryB = pivotB == 0 ? INT_MIN : biggerNums[pivotB - 1];
      int rightBoundaryB = pivotB == nb ? INT_MAX : biggerNums[pivotB];

      if (leftBoundaryS <= rightBoundaryB && leftBoundaryB <= rightBoundaryS) {
        if ((ns + nb) % 2 == 0) {
          return (double)(((double)max(leftBoundaryS, leftBoundaryB) +
                           (double)min(rightBoundaryS, rightBoundaryB)) /
                          2);
        } else {
          return (double)(max(leftBoundaryS, leftBoundaryB));
        }
      } else if (leftBoundaryS > rightBoundaryB) {
        end = pivotS - 1;
      } else {
        start = pivotS + 1;
      }
    }

    return (double)0;
  }
};

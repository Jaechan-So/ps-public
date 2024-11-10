// 658. Find K Closest Elements
// https://leetcode.com/problems/find-k-closest-elements/

using namespace std;

#include <vector>

class Solution {
public:
  vector<int> findClosestElements(vector<int> &arr, int k, int x) {
    int mid = lower_bound(arr.begin(), arr.end(), x) - arr.begin();
    if (mid >= arr.size() || mid > 0 && arr[mid] - x >= x - arr[mid - 1]) {
      mid -= 1;
    }

    int left = mid - 1, right = mid + 1;
    for (int i = 0; i < k - 1; i++) {
      if (left < 0) {
        right++;
        continue;
      }

      if (right >= arr.size()) {
        left--;
        continue;
      }

      if (x - arr[left] <= arr[right] - x) {
        left--;
      } else {
        right++;
      }
    }

    return vector<int>(arr.begin() + left + 1, arr.begin() + right);
  }
};

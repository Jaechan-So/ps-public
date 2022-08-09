// 1352. Product of the Last K Numbers
// https://leetcode.com/problems/product-of-the-last-k-numbers/

using namespace std;

#include <map>
#include <vector>

class ProductOfNumbers {
public:
  map<int, int>
      productOfIntervalWithStartNum; // (key: startNum, value: non-recent
                                     // product from startNum)
  vector<int> lazyNums;              // Not updated number
  int notUpdatedProduct = 1;         // Not updated product

  ProductOfNumbers() {}

  void add(int num) {
    lazyNums.push_back(num);
    notUpdatedProduct *= num;
  }

  int getProduct(int k) {
    if (lazyNums.size() == 0) {
      return productOfIntervalWithStartNum
          [productOfIntervalWithStartNum.size() - k];
    }

    // Update previous products.
    for (int i = productOfIntervalWithStartNum.size() - 1; i >= 0; i--) {
      if (productOfIntervalWithStartNum[i] == 0) {
        break;
      }
      productOfIntervalWithStartNum[i] *= notUpdatedProduct;
    }

    // Record not updated products.
    int targetIndex =
            productOfIntervalWithStartNum.size() + lazyNums.size() - 1,
        lazyProduct = 1;
    for (auto iter = lazyNums.rbegin(); iter != lazyNums.rend(); iter++) {
      int target = *iter;
      lazyProduct *= target;
      productOfIntervalWithStartNum[targetIndex] = lazyProduct;

      targetIndex--;
    }

    // Clear local variables.
    lazyNums.clear();
    notUpdatedProduct = 1;

    return productOfIntervalWithStartNum[productOfIntervalWithStartNum.size() -
                                         k];
  }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */

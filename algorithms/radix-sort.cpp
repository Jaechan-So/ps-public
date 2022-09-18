using namespace std;

#include <algorithm>
#include <assert.h>
#include <iostream>
#include <vector>

class RadixSort {
public:
  vector<int> radixSort(vector<int> &v) {
    int maxElement = *max_element(v.begin(), v.end()),
        minElement = *min_element(v.begin(), v.end());

    // Consider only positive integers.
    assert(minElement > 0);
    assert(maxElement <= INT_MAX);

    // Get iteration count by maximum exponent.
    int iteration = getExponent(maxElement);

    vector<int> elements(v), partial(v.size());
    for (int i = 0; i < iteration; i++) {
      vector<int> count(RADIX, 0);

      for (int j = 0; j < elements.size(); j++) {
        count[getDigitWithOrder(elements[j], i)]++;
      }

      for (int j = 1; j < count.size(); j++) {
        count[j] += count[j - 1];
      }

      for (int j = elements.size() - 1; j >= 0; j--) {
        partial[--count[getDigitWithOrder(elements[j], i)]] = elements[j];
      }

      for (int j = 0; j < elements.size(); j++) {
        elements[j] = partial[j];
      }
    }

    return elements;
  }

private:
  const int RADIX = 10;

  int getExponent(int i) {
    int exponent = 0;

    while (i) {
      exponent++;
      i /= RADIX;
    }

    return exponent;
  }

  int getDigitWithOrder(int i, int order) {
    return (i / getPowerOfRadix(order)) % RADIX;
  }

  int getPowerOfRadix(int i) {
    int powerOfRadix = 1;

    while (i) {
      powerOfRadix *= RADIX;
      i--;
    }

    return powerOfRadix;
  }
};

int main() {
  RadixSort rs;
  vector<int> testV({41, 36, 90, 81, 81, 22, 22, 20, 79, 16});

  vector<int> radixSortResult = rs.radixSort(testV);

  vector<int> stdSortResult(testV);
  sort(stdSortResult.begin(), stdSortResult.end());

  for (int i = 0; i < testV.size(); i++) {
    assert(radixSortResult[i] == stdSortResult[i]);
  }
  cout << "Test Success: Radix Sort Result is same as Standard Sort Result."
       << '\n';

  return 0;
}

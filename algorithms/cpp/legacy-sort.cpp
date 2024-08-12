// Sorting algorithms for integer sequences.
// All sorting algorithms are based on ascending order.
// This can be extended with generics and class.

#include <algorithm>
#include <cassert>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

// Selection sort algorithm.
vector<int> SelectionSort(vector<int> v) {
  int len = v.size();
  for (int i = 0; i < len; i++) {
    int swap_index = i;
    for (int j = i + 1; j < len; j++) {
      if (v[swap_index] > v[j]) {
        swap_index = j;
      }
    }
    swap(v[i], v[swap_index]);
  }
  return v;
}

// Insertion sort algorithm.
vector<int> InsertionSort(vector<int> v) {
  int len = v.size();
  for (int i = 0; i < len; i++) {
    for (int j = 0; j < i; j++) {
      if (v[j] > v[i]) {
        for (int k = i - 1; k >= j; k--) {
          swap(v[k], v[k + 1]);
        }
        break;
      }
    }
  }
  return v;
}

// Bubble sort algorithm.
vector<int> BubbleSort(vector<int> v) {
  int len = v.size();
  for (int i = len; i >= 1; i--) {
    for (int j = 0; j < i - 1; j++) {
      if (v[j] > v[j + 1]) {
        swap(v[j], v[j + 1]);
      }
    }
  }
  return v;
}

int _Partition(vector<int> &v, int first, int last) {
  if (v.size() == 1) {
    return 0;
  } else {
    int pivot = v[first];
    int partition = first;
    for (int i = first + 1; i <= last; i++) {
      if (v[i] <= pivot) {
        partition++;
        swap(v[i], v[partition]);
      }
    }
    swap(v[first], v[partition]);
    return partition;
  }
}

// Quicksort algorithm.
vector<int> QuickSort(vector<int> &v, int first, int last) {
  int len = v.size();
  if (first < last) {
    int loc = _Partition(v, first, last);
    QuickSort(v, first, loc - 1);
    QuickSort(v, loc + 1, last);
  }
  return v;
}

void _Merge(vector<int> &v, int first, int mid, int last) {
  vector<int> sorted_vector;
  int cursor1 = first, cursor2 = mid + 1;

  while (cursor1 <= mid && cursor2 <= last) {
    if (v[cursor1] <= v[cursor2]) {
      sorted_vector.push_back(v[cursor1]);
      cursor1++;
    } else {
      sorted_vector.push_back(v[cursor2]);
      cursor2++;
    }
  }

  if (cursor1 > mid) {
    for (int i = cursor2; i <= last; i++) {
      sorted_vector.push_back(v[i]);
    }
  } else if (cursor2 > last) {
    for (int i = cursor1; i <= mid; i++) {
      sorted_vector.push_back(v[i]);
    }
  }

  for (int i = first; i <= last; i++) {
    v[i] = sorted_vector[i - first];
  }
}

// Mergesort algorithm.
vector<int> MergeSort(vector<int> &v, int first, int last) {
  int mid = (first + last) / 2;
  if (first < last) {
    MergeSort(v, first, mid);
    MergeSort(v, mid + 1, last);
    _Merge(v, first, mid, last);
  }
  return v;
}

// Counting Sort algorithm.
vector<int> CountingSort(vector<int> v) {
  map<int, int> totalSums;
  for (int i = 0; i < v.size(); i++) {
    if (totalSums.find(v[i]) != totalSums.end()) {
      totalSums[v[i]] += 1;
    } else {
      totalSums[v[i]] = 1;
    }
  }
  int totalAccSum = 0;
  map<int, int> totalAccSums;
  for (map<int, int>::iterator iter = totalSums.begin();
       iter != totalSums.end(); iter++) {
    totalAccSum += iter->second;
    totalAccSums[iter->first] = totalAccSum;
  }

  vector<int> sorted_vector;
  sorted_vector.reserve(v.size());
  for (int i = 0; i < v.size(); i++) {
    sorted_vector[totalAccSums[v[i]]--] = v[i];
  }

  return sorted_vector;
}

void TestSelectionSort() {
  vector<int> test_vector;
  test_vector.push_back(1);
  test_vector.push_back(4);
  test_vector.push_back(2);
  test_vector.push_back(7);
  test_vector.push_back(3);
  test_vector.push_back(6);
  test_vector.push_back(5);
  vector<int> sorted_vector = SelectionSort(test_vector);
  for (vector<int>::iterator iter = sorted_vector.begin();
       iter != sorted_vector.end(); iter++) {
    cout << *iter << endl;
  }
}

void TestInsertionSort() {
  vector<int> test_vector;
  test_vector.push_back(1);
  test_vector.push_back(4);
  test_vector.push_back(2);
  test_vector.push_back(7);
  test_vector.push_back(3);
  test_vector.push_back(6);
  test_vector.push_back(5);
  vector<int> sorted_vector = InsertionSort(test_vector);
  for (vector<int>::iterator iter = sorted_vector.begin();
       iter != sorted_vector.end(); iter++) {
    cout << *iter << endl;
  }
}

void TestBubbleSort() {
  vector<int> test_vector;
  test_vector.push_back(1);
  test_vector.push_back(4);
  test_vector.push_back(2);
  test_vector.push_back(7);
  test_vector.push_back(3);
  test_vector.push_back(6);
  test_vector.push_back(5);
  vector<int> sorted_vector = BubbleSort(test_vector);
  for (vector<int>::iterator iter = sorted_vector.begin();
       iter != sorted_vector.end(); iter++) {
    cout << *iter << endl;
  }
}

void TestQuickSort() {
  vector<int> test_vector;
  test_vector.push_back(1);
  test_vector.push_back(4);
  test_vector.push_back(2);
  test_vector.push_back(7);
  test_vector.push_back(3);
  test_vector.push_back(6);
  test_vector.push_back(5);
  vector<int> sorted_vector = QuickSort(test_vector, 0, test_vector.size() - 1);
  for (vector<int>::iterator iter = sorted_vector.begin();
       iter != sorted_vector.end(); iter++) {
    cout << *iter << endl;
  }
}

void TestMergeSort() {
  vector<int> test_vector;
  test_vector.push_back(1);
  test_vector.push_back(4);
  test_vector.push_back(2);
  test_vector.push_back(7);
  test_vector.push_back(3);
  test_vector.push_back(6);
  test_vector.push_back(5);
  vector<int> sorted_vector = MergeSort(test_vector, 0, test_vector.size() - 1);
  for (vector<int>::iterator iter = sorted_vector.begin();
       iter != sorted_vector.end(); iter++) {
    cout << *iter << endl;
  }
}

void TestCountingSort() {
  vector<int> test_vector;
  test_vector.push_back(1);
  test_vector.push_back(4);
  test_vector.push_back(2);
  test_vector.push_back(7);
  test_vector.push_back(3);
  test_vector.push_back(6);
  test_vector.push_back(5);
  vector<int> sorted_vector = CountingSort(test_vector);
  for (vector<int>::iterator iter = sorted_vector.begin();
       iter != sorted_vector.end(); iter++) {
    cout << *iter << endl;
  }
}

int main() {
  TestSelectionSort();
  cout << "-------" << endl;
  TestInsertionSort();
  cout << "-------" << endl;
  TestBubbleSort();
  cout << "-------" << endl;
  TestQuickSort();
  cout << "-------" << endl;
  TestMergeSort();
  cout << "-------" << endl;
  TestCountingSort();
}

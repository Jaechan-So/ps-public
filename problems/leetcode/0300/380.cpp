// 380. Insert Delete GetRandom O(1)
// https://leetcode.com/problems/insert-delete-getrandom-o1/description/

using namespace std;

#include <unordered_map>
#include <vector>

class RandomizedSet {
public:
  unordered_map<int, int> entryToIndex;
  vector<int> v;

  RandomizedSet() {}

  bool insert(int val) {
    if (entryToIndex.find(val) != entryToIndex.end()) {
      return false;
    }

    entryToIndex[val] = v.size();
    v.push_back(val);
    return true;
  }

  bool remove(int val) {
    if (entryToIndex.find(val) == entryToIndex.end()) {
      return false;
    }

    int lastEntryIndex = entryToIndex[v.back()],
        valEntryIndex = entryToIndex[val];
    entryToIndex[v.back()] = valEntryIndex;
    entryToIndex.erase(val);

    swap(v[lastEntryIndex], v[valEntryIndex]);
    v.pop_back();
    return true;
  }

  int getRandom() { return v[rand() % v.size()]; }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */

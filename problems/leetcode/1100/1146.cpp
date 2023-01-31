// 1146. Snapshot Array
// https://leetcode.com/problems/snapshot-array/description/

using namespace std;

#include <vector>

typedef pair<int, int> pii;

bool comp(const pii &a, const pii &b) { return a.first < b.first; }

class SnapshotArray {
public:
  vector<vector<pii>> snapshots;
  int snapshotCount, snapshotLength;

  SnapshotArray(int length) {
    snapshots = vector<vector<pii>>(length, vector<pii>());
    snapshotCount = 0;
    snapshotLength = length;
  }

  void set(int index, int val) {
    if (snapshots[index].empty()) {
      snapshots[index].push_back({0, val});
      return;
    }

    if (snapshots[index].back().first == snapshotCount) {
      snapshots[index].back().second = val;
    } else {
      snapshots[index].push_back({snapshotCount, val});
    }
  }

  int snap() {
    if (snapshotCount == 0) {
      for (int i = 0; i < snapshotLength; i++) {
        if (snapshots[i].empty()) {
          snapshots[i].push_back({0, 0});
        }
      }
    }
    snapshotCount++;
    return snapshotCount - 1;
  }

  int get(int index, int snap_id) {
    if (snap_id == 0) {
      return snapshots[index][0].second;
    }

    vector<pii>::iterator iter =
        lower_bound(snapshots[index].begin(), snapshots[index].end(),
                    pii(snap_id, 0), comp);
    if (iter != snapshots[index].end() && iter->first == snap_id) {
      return iter->second;
    }
    return prev(iter)->second;
  }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */

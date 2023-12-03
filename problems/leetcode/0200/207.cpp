// 207. Course Schedule
// https://leetcode.com/problems/course-schedule/description/

using namespace std;

#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <vector>

class Solution {
public:
  bool canFinish(int numCourses, vector<vector<int>> &prerequisites) {
    int remain = numCourses;
    vector<int> prerequisiteCounts(numCourses, 0);
    unordered_map<int, unordered_set<int>> nextCourses;

    for (vector<int> &prerequisite : prerequisites) {
      int next = prerequisite[0], prev = prerequisite[1];
      nextCourses[prev].insert(next);
      prerequisiteCounts[next]++;
    }

    queue<int> courses;
    for (int i = 0; i < numCourses; i++) {
      if (prerequisiteCounts[i] == 0) {
        courses.push(i);
      }
    }

    while (!courses.empty()) {
      int course = courses.front();
      courses.pop();
      remain--;

      for (int next : nextCourses[course]) {
        prerequisiteCounts[next]--;
        if (prerequisiteCounts[next] == 0) {
          courses.push(next);
        }
      }
    }

    return remain == 0;
  }
};

// Topological Sort를 이용해서가능한 모든 수업을 수강했을 때 numCourses만큼
// 수강했는지 아닌지.
// 1. 특정 과목을 수강했을 때, 이 과목을 선수과목으로 가지고 있던 과목이
// 무엇인지

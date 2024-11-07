// 210. Course Schedule II
// https://leetcode.com/problems/course-schedule-ii/

using namespace std;

#include <map>
#include <set>
#include <vector>

class Solution {
public:
  vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites) {
    vector<int> answer;
    map<int, set<int>> innerVertices, outerVertices;
    set<int> initialCandidates;

    for (int i = 0; i < numCourses; i++) {
      initialCandidates.insert(i);
    }

    for (auto &prerequisite : prerequisites) {
      int earlier = prerequisite[1], later = prerequisite[0];
      innerVertices[later].insert(earlier);
      outerVertices[earlier].insert(later);
      initialCandidates.erase(later);
    }

    for (auto &course : initialCandidates) {
      answer.push_back(course);
    }

    int i = 0;
    while (i < answer.size()) {
      int course = answer[i];

      for (auto &nextCourse : outerVertices[course]) {
        innerVertices[nextCourse].erase(course);
        if (innerVertices[nextCourse].size() == 0) {
          answer.push_back(nextCourse);
        }
      }

      i++;
    }

    if (answer.size() != numCourses) {
      answer.clear();
    }

    return answer;
  }
};

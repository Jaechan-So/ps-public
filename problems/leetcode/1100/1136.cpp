// 1136. Parallel Courses
// https://leetcode.com/problems/parallel-courses/description/

using namespace std;

#include <queue>
#include <vector>

class Solution {
public:
  int minimumSemesters(int n, vector<vector<int>> &relations) {
    vector<int> indegrees(n + 1, 0);
    vector<vector<int>> graph(n + 1);
    for (int i = 0; i < relations.size(); i++) {
      int prevCourse = relations[i][0], nextCourse = relations[i][1];
      indegrees[nextCourse]++;
      graph[prevCourse].push_back(nextCourse);
    }

    queue<int> courses;
    for (int i = 1; i <= n; i++) {
      if (indegrees[i] == 0) {
        courses.push(i);
      }
    }

    int semesters = 0, passedCourses = 0;
    while (!courses.empty()) {
      semesters++;

      vector<int> currentSemesterCourses;
      while (!courses.empty()) {
        currentSemesterCourses.push_back(courses.front());
        courses.pop();
      }
      passedCourses += currentSemesterCourses.size();

      for (int i = 0; i < currentSemesterCourses.size(); i++) {
        int course = currentSemesterCourses[i];
        for (int j = 0; j < graph[course].size(); j++) {
          int nextCourse = graph[course][j];
          if (--indegrees[nextCourse] == 0) {
            courses.push(nextCourse);
          }
        }
      }
    }

    return passedCourses == n ? semesters : -1;
  }
};

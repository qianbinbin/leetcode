#include "CourseSchedule.h"
#include <cassert>

using namespace lcpp;

bool Solution207_1::canFinish(int numCourses,
                              std::vector<std::pair<int, int>> &prerequisites) {
  assert(numCourses >= 0);
  std::vector<int> Prev(numCourses);
  std::vector<std::vector<int>> Graph(numCourses);
  for (const auto &Edge : prerequisites) {
    ++Prev[Edge.second];
    Graph[Edge.first].push_back(Edge.second);
  }
  std::vector<int> Nodes;
  for (int N = 0; N != numCourses; ++N) {
    if (Prev[N] == 0)
      Nodes.push_back(N);
  }
  while (!Nodes.empty()) {
    auto &Next = Graph[Nodes.back()];
    Nodes.pop_back();
    for (const auto &N : Next) {
      if (--Prev[N] == 0)
        Nodes.push_back(N);
    }
    Next.clear();
    --numCourses;
  }
  return numCourses == 0;
}

// There are a total of n courses you have to take, labeled from 0 to n-1.
//
// Some courses may have prerequisites, for example to take course 0 you have to
// first take course 1, which is expressed as a pair: [0,1]
//
// Given the total number of courses and a list of prerequisite pairs, is it
// possible for you to finish all courses?
//
// Example 1:
//
// Input: 2, [[1,0]]
// Output: true
// Explanation: There are a total of 2 courses to take.
// To take course 1 you should have finished course 0. So it is possible.
//
// Example 2:
//
// Input: 2, [[1,0],[0,1]]
// Output: false
// Explanation: There are a total of 2 courses to take.
// To take course 1 you should have finished course 0, and to take course 0 you
// should also have finished course 1. So it is impossible.
//
// Note:
//
// 1. The input prerequisites is a graph represented by a list of edges, not
// adjacency matrices. Read more about how a graph is represented.
// 2. You may assume that there are no duplicate edges in the input
// prerequisites.

#ifndef LEETCODECPP_COURSESCHEDULE_H
#define LEETCODECPP_COURSESCHEDULE_H

#include <utility>
#include <vector>

namespace lcpp {

class Solution207_1 {
public:
  bool canFinish(int numCourses,
                 std::vector<std::pair<int, int>> &prerequisites);
};

} // namespace lcpp

#endif // LEETCODECPP_COURSESCHEDULE_H

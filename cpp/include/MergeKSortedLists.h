// Merge k sorted linked lists and return it as one sorted list. Analyze and
// describe its complexity.
//
// Example:
//
// Input:
// [
//   1->4->5,
//   1->3->4,
//   2->6
// ]
// Output: 1->1->2->3->4->4->5->6

#ifndef LEETCODECPP_MERGEKSORTEDLISTS_H
#define LEETCODECPP_MERGEKSORTEDLISTS_H

#include "ListNode.h"
#include <vector>

namespace lcpp {

class Solution23_1 {
public:
  ListNode *mergeKLists(std::vector<ListNode *> &lists);
};

class Solution23_2 {
public:
  ListNode *mergeKLists(std::vector<ListNode *> &lists);
};

}

#endif //LEETCODECPP_MERGEKSORTEDLISTS_H

// Merge two sorted linked lists and return it as a new list. The new list
// should be made by splicing together the nodes of the first two lists.
//
// Example:
//
// Input: 1->2->4, 1->3->4
// Output: 1->1->2->3->4->4

#ifndef LEETCODECPP_MERGETWOSORTEDLISTS_H
#define LEETCODECPP_MERGETWOSORTEDLISTS_H

#include "ListNode.h"

namespace lcpp {

class Solution21_1 {
public:
  ListNode *mergeTwoLists(ListNode *l1, ListNode *l2);
};

}

#endif //LEETCODECPP_MERGETWOSORTEDLISTS_H

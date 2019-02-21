// Given a sorted linked list, delete all duplicates such that each element
// appear only once.
//
// Example 1:
//
// Input: 1->1->2
// Output: 1->2
//
// Example 2:
//
// Input: 1->1->2->3->3
// Output: 1->2->3

#ifndef LEETCODECPP_REMOVEDUPLICATESFROMSORTEDLIST_H
#define LEETCODECPP_REMOVEDUPLICATESFROMSORTEDLIST_H

#include "ListNode.h"

namespace lcpp {

class Solution83_1 {
public:
  ListNode *deleteDuplicates(ListNode *head);
};

}

#endif //LEETCODECPP_REMOVEDUPLICATESFROMSORTEDLIST_H

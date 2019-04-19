// Reverse a singly linked list.
//
// Example:
//
// Input: 1->2->3->4->5->NULL
// Output: 5->4->3->2->1->NULL
//
// Follow up:
//
// A linked list can be reversed either iteratively or recursively. Could you
// implement both?

#ifndef LEETCODECPP_REVERSELINKEDLIST_H
#define LEETCODECPP_REVERSELINKEDLIST_H

#include "ListNode.h"

namespace lcpp {

class Solution206_1 {
public:
  ListNode *reverseList(ListNode *head);
};

} // namespace lcpp

#endif // LEETCODECPP_REVERSELINKEDLIST_H

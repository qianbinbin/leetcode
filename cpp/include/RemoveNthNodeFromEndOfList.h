// Given a linked list, remove the n-th node from the end of list and return its
// head.
//
// Example:
//
// Given linked list: 1->2->3->4->5, and n = 2.
//
// After removing the second node from the end, the linked list becomes
// 1->2->3->5.
//
// Note:
//
// Given n will always be valid.
//
// Follow up:
//
// Could you do this in one pass?

#ifndef LEETCODECPP_REMOVENTHNODEFROMENDOFLIST_H
#define LEETCODECPP_REMOVENTHNODEFROMENDOFLIST_H

#include "ListNode.h"

namespace lcpp {

class Solution19_1 {
public:
  ListNode *removeNthFromEnd(ListNode *head, int n);
};

}

#endif //LEETCODECPP_REMOVENTHNODEFROMENDOFLIST_H

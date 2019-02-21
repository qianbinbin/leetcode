// Given a linked list, swap every two adjacent nodes and return its head.
//
// You may not modify the values in the list's nodes, only nodes itself may be
// changed.
//
//
//
// Example:
//
// Given 1->2->3->4, you should return the list as 2->1->4->3.

#ifndef LEETCODECPP_SWAPNODESINPAIRS_H
#define LEETCODECPP_SWAPNODESINPAIRS_H

#include "ListNode.h"

namespace lcpp {

class Solution24_1 {
public:
  ListNode *swapPairs(ListNode *head);
};

}

#endif //LEETCODECPP_SWAPNODESINPAIRS_H

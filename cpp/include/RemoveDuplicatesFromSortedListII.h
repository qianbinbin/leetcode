// Given a sorted linked list, delete all nodes that have duplicate numbers,
// leaving only distinct numbers from the original list.
//
// Example 1:
//
// Input: 1->2->3->3->4->4->5
// Output: 1->2->5
//
// Example 2:
//
// Input: 1->1->1->2->3
// Output: 2->3

#ifndef LEETCODECPP_REMOVEDUPLICATESFROMSORTEDLISTII_H
#define LEETCODECPP_REMOVEDUPLICATESFROMSORTEDLISTII_H

#include "ListNode.h"

namespace lcpp {

class Solution82_1 {
public:
  ListNode *deleteDuplicates(ListNode *head);
};

}

#endif //LEETCODECPP_REMOVEDUPLICATESFROMSORTEDLISTII_H

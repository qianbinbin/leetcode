// Reverse a linked list from position m to n. Do it in one-pass.
//
// Note: 1 ≤ m ≤ n ≤ length of list.
//
// Example:
//
// Input: 1->2->3->4->5->NULL, m = 2, n = 4
// Output: 1->4->3->2->5->NULL

#ifndef LEETCODECPP_REVERSELINKEDLISTII_H
#define LEETCODECPP_REVERSELINKEDLISTII_H

#include "ListNode.h"

namespace lcpp {

class Solution92_1 {
public:
  ListNode *reverseBetween(ListNode *head, int m, int n);
};

}

#endif //LEETCODECPP_REVERSELINKEDLISTII_H

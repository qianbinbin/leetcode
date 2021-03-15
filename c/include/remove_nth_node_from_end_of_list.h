/*
 * Given the head of a linked list, remove the nth node from the end of the list and return its head.
 *
 * Follow up: Could you do this in one pass?
 *
 *
 *
 * Example 1:
 *
 * https://assets.leetcode.com/uploads/2020/10/03/remove_ex1.jpg
 *
 * Input: head = [1,2,3,4,5], n = 2
 * Output: [1,2,3,5]
 *
 * Example 2:
 *
 * Input: head = [1], n = 1
 * Output: []
 *
 * Example 3:
 *
 * Input: head = [1,2], n = 1
 * Output: [1]
 *
 *
 * Constraints:
 *
 * The number of nodes in the list is sz.
 * 1 <= sz <= 30
 * 0 <= Node.val <= 100
 * 1 <= n <= sz
 */

#ifndef LEETCODE_REMOVE_NTH_NODE_FROM_END_OF_LIST_H
#define LEETCODE_REMOVE_NTH_NODE_FROM_END_OF_LIST_H

#include "common.h"

struct ListNode *removeNthFromEnd_19_1(struct ListNode *head, int n);

#endif //LEETCODE_REMOVE_NTH_NODE_FROM_END_OF_LIST_H

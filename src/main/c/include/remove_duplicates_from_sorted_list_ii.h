/*
 * Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.
 *
 * Example 1:
 *
 * Input: 1->2->3->3->4->4->5
 * Output: 1->2->5
 *
 * Example 2:
 *
 * Input: 1->1->1->2->3
 * Output: 2->3
 */

#ifndef LEETCODE_REMOVE_DUPLICATES_FROM_SORTED_LIST_II_H
#define LEETCODE_REMOVE_DUPLICATES_FROM_SORTED_LIST_II_H

#include "common.h"

struct ListNode *deleteDuplicates_82_1(struct ListNode *head);

#endif //LEETCODE_REMOVE_DUPLICATES_FROM_SORTED_LIST_II_H

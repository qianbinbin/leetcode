/*
 * Given a sorted linked list, delete all duplicates such that each element appear only once.
 *
 * Example 1:
 *
 * Input: 1->1->2
 * Output: 1->2
 *
 * Example 2:
 *
 * Input: 1->1->2->3->3
 * Output: 1->2->3
 */

#ifndef LEETCODE_REMOVE_DUPLICATES_FROM_SORTED_LIST_H
#define LEETCODE_REMOVE_DUPLICATES_FROM_SORTED_LIST_H

#include "common.h"

struct ListNode *deleteDuplicates_83_1(struct ListNode *head);

#endif //LEETCODE_REMOVE_DUPLICATES_FROM_SORTED_LIST_H

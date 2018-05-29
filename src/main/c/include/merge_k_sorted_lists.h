/*
 * Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.
 *
 * Example:
 *
 * Input:
 * [
 *   1->4->5,
 *   1->3->4,
 *   2->6
 * ]
 * Output: 1->1->2->3->4->4->5->6
 */

#ifndef LEETCODE_MERGE_K_SORTED_LISTS_H
#define LEETCODE_MERGE_K_SORTED_LISTS_H

#include "common.h"

struct ListNode *mergeKLists_23_1(struct ListNode **lists, int listsSize);

struct ListNode *mergeKLists_23_2(struct ListNode **lists, int listsSize);

#endif //LEETCODE_MERGE_K_SORTED_LISTS_H

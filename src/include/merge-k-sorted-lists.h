#ifndef LEETCODE_MERGE_K_SORTED_LISTS_H
#define LEETCODE_MERGE_K_SORTED_LISTS_H

#include <common.h>

/**
 * Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.
 *
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *mergeKLists_23(struct ListNode **lists, int listsSize);

#endif //LEETCODE_MERGE_K_SORTED_LISTS_H

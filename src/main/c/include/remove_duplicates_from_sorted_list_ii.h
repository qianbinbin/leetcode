#ifndef LEETCODE_REMOVE_DUPLICATES_FROM_SORTED_LIST_II_H
#define LEETCODE_REMOVE_DUPLICATES_FROM_SORTED_LIST_II_H

#include <common.h>

/**
 * Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.
 *
 * For example,
 * Given 1->2->3->3->4->4->5, return 1->2->5.
 * Given 1->1->1->2->3, return 2->3.
 *
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *deleteDuplicates_82(struct ListNode *head);

#endif //LEETCODE_REMOVE_DUPLICATES_FROM_SORTED_LIST_II_H

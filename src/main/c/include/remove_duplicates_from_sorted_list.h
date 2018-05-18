#ifndef LEETCODE_REMOVE_DUPLICATES_FROM_SORTED_LIST_H
#define LEETCODE_REMOVE_DUPLICATES_FROM_SORTED_LIST_H

#include <common.h>

/**
 * Given a sorted linked list, delete all duplicates such that each element appear only once.
 *
 * For example,
 * Given 1->1->2, return 1->2.
 * Given 1->1->2->3->3, return 1->2->3.
 *
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *deleteDuplicates_83(struct ListNode *head);

#endif //LEETCODE_REMOVE_DUPLICATES_FROM_SORTED_LIST_H

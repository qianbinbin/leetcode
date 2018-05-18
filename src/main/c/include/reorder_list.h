#ifndef LEETCODE_REORDER_LIST_H
#define LEETCODE_REORDER_LIST_H

#include <common.h>

/**
 * Given a singly linked list L: L0→L1→…→Ln-1→Ln,
 * reorder it to: L0→Ln→L1→Ln-1→L2→Ln-2→…
 *
 * You must do this in-place without altering the nodes' values.
 *
 * For example,
 * Given {1,2,3,4}, reorder it to {1,4,2,3}.
 *
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
void reorderList_143(struct ListNode *head);

#endif //LEETCODE_REORDER_LIST_H

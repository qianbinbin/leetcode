/*
 * Reverse a linked list from position m to n. Do it in one-pass.
 *
 * Note: 1 ≤ m ≤ n ≤ length of list.
 *
 * Example:
 *
 * Input: 1->2->3->4->5->NULL, m = 2, n = 4
 * Output: 1->4->3->2->5->NULL
 */

#ifndef LEETCODE_REVERSE_LINKED_LIST_II_H
#define LEETCODE_REVERSE_LINKED_LIST_II_H

#include "common.h"

struct ListNode *reverseBetween_92_1(struct ListNode *head, int m, int n);

#endif //LEETCODE_REVERSE_LINKED_LIST_II_H

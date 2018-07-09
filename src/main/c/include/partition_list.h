/*
 * Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.
 *
 * You should preserve the original relative order of the nodes in each of the two partitions.
 *
 * Example:
 *
 * Input: head = 1->4->3->2->5->2, x = 3
 * Output: 1->2->2->4->3->5
 */

#ifndef LEETCODE_PARTITION_LIST_H
#define LEETCODE_PARTITION_LIST_H

#include "common.h"

struct ListNode *partition_86_1(struct ListNode *head, int x);

#endif //LEETCODE_PARTITION_LIST_H

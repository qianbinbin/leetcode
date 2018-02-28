#ifndef LEETCODE_PARTITION_LIST_H
#define LEETCODE_PARTITION_LIST_H

#include <common.h>

/**
 * Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.
 *
 * You should preserve the original relative order of the nodes in each of the two partitions.
 *
 * For example,
 * Given 1->4->3->2->5->2 and x = 3,
 * return 1->2->2->4->3->5.
 *
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *partition_86(struct ListNode *head, int x);

#endif //LEETCODE_PARTITION_LIST_H

/*
 * Given a string containing only digits, restore it by returning all possible valid IP address combinations.
 *
 * Example:
 *
 * Input: "25525511135"
 * Output: ["255.255.11.135", "255.255.111.35"]
 */

#ifndef LEETCODE_RESTORE_IP_ADDRESSES_H
#define LEETCODE_RESTORE_IP_ADDRESSES_H

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
char **restoreIpAddresses_93_1(char *s, int *returnSize);

char **restoreIpAddresses_93_2(char *s, int *returnSize);

#endif //LEETCODE_RESTORE_IP_ADDRESSES_H

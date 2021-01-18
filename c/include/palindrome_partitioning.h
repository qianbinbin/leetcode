/*
 * Given a string s, partition s such that every substring of the partition is a palindrome.
 *
 * Return all possible palindrome partitioning of s.
 *
 * Example:
 *
 * Input: "aab"
 * Output:
 * [
 *   ["aa","b"],
 *   ["a","a","b"]
 * ]
 */

#ifndef LEETCODE_PALINDROME_PARTITIONING_H
#define LEETCODE_PALINDROME_PARTITIONING_H

char ***partition_131_1(char *s, int **columnSizes, int *returnSize);

#endif //LEETCODE_PALINDROME_PARTITIONING_H

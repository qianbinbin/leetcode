#ifndef LEETCODE_PALINDROME_PARTITIONING_H
#define LEETCODE_PALINDROME_PARTITIONING_H

/**
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
 *
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *columnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

/**
 * Depth-first search
 */
char ***partition_131_1(char *s, int **columnSizes, int *returnSize);

#endif //LEETCODE_PALINDROME_PARTITIONING_H

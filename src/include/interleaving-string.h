#ifndef LEETCODE_INTERLEAVING_STRING_H
#define LEETCODE_INTERLEAVING_STRING_H

#include <stdbool.h>

/**
 * Given s1, s2, s3, find whether s3 is formed by the interleaving of s1 and s2.
 *
 * Example 1:
 *
 * Input: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbcbcac"
 * Output: true
 *
 * Example 2:
 *
 * Input: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbbaccc"
 * Output: false
 */
bool isInterleave_97(char *s1, char *s2, char *s3);

#endif //LEETCODE_INTERLEAVING_STRING_H
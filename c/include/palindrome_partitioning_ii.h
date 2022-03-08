/*
 * Given a string s, partition s such that every substring of the partition is a palindrome.
 *
 * Return the minimum cuts needed for a palindrome partitioning of s.
 *
 *
 *
 * Example 1:
 *
 * Input: s = "aab"
 * Output: 1
 * Explanation: The palindrome partitioning ["aa","b"] could be produced using 1 cut.
 *
 * Example 2:
 *
 * Input: s = "a"
 * Output: 0
 *
 * Example 3:
 *
 * Input: s = "ab"
 * Output: 1
 *
 *
 * Constraints:
 *
 * 1 <= s.length <= 2000
 * s consists of lower-case English letters only.
 */

#ifndef LEETCODE_PALINDROME_PARTITIONING_II_H
#define LEETCODE_PALINDROME_PARTITIONING_II_H

int minCut_132_1(char *s);

int minCut_132_2(char *s);

#endif //LEETCODE_PALINDROME_PARTITIONING_II_H

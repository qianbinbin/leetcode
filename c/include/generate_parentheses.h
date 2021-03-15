/*
 * Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.
 *
 *
 *
 * Example 1:
 *
 * Input: n = 3
 * Output: ["((()))","(()())","(())()","()(())","()()()"]
 *
 * Example 2:
 *
 * Input: n = 1
 * Output: ["()"]
 *
 *
 * Constraints:
 *
 * 1 <= n <= 8
 */

#ifndef LEETCODE_GENERATE_PARENTHESES_H
#define LEETCODE_GENERATE_PARENTHESES_H

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char **generateParenthesis_22_1(int n, int *returnSize);

#endif //LEETCODE_GENERATE_PARENTHESES_H

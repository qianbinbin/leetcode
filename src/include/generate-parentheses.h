#ifndef LEETCODE_GENERATE_PARENTHESES_H
#define LEETCODE_GENERATE_PARENTHESES_H

/**
 * Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.
 *
 * For example, given n = 3, a solution set is:
 *
 * [
 *   "((()))",
 *   "(()())",
 *   "(())()",
 *   "()(())",
 *   "()()()"
 * ]
 *
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */

char **generateParenthesis_22_1(int n, int *returnSize);

#endif //LEETCODE_GENERATE_PARENTHESES_H

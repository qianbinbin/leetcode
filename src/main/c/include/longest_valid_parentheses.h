#ifndef LEETCODE_LONGEST_VALID_PARENTHESES_H
#define LEETCODE_LONGEST_VALID_PARENTHESES_H

/**
 * Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) parentheses substring.
 *
 * For "(()", the longest valid parentheses substring is "()", which has length = 2.
 *
 * Another example is ")()())", where the longest valid parentheses substring is "()()", which has length = 4.
 */

/**
 * Brute force, O(n^2)
 */
int longestValidParentheses_32_1(char *s);

/**
 * Using stack, O(n)
 */
int longestValidParentheses_32_2(char *s);

/**
 * Dynamic programming, O(n)
 */
int longestValidParentheses_32_3(char *s);

/**
 * Two scans, O(n)
 */
int longestValidParentheses_32_4(char *s);

#endif //LEETCODE_LONGEST_VALID_PARENTHESES_H

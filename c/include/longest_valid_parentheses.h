/*
 * Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) parentheses substring.
 *
 * Example 1:
 *
 * Input: "(()"
 * Output: 2
 * Explanation: The longest valid parentheses substring is "()"
 *
 * Example 2:
 *
 * Input: ")()())"
 * Output: 4
 * Explanation: The longest valid parentheses substring is "()()"
 */

#ifndef LEETCODE_LONGEST_VALID_PARENTHESES_H
#define LEETCODE_LONGEST_VALID_PARENTHESES_H

/**
 * Two passes
 */
int longestValidParentheses_32_1(char *s);

/**
 * Using stack
 */
int longestValidParentheses_32_2(char *s);

/**
 * Dynamic programming
 */
int longestValidParentheses_32_3(char *s);

#endif //LEETCODE_LONGEST_VALID_PARENTHESES_H

/*
 * Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) parentheses substring.
 *
 *
 *
 * Example 1:
 *
 * Input: s = "(()"
 * Output: 2
 * Explanation: The longest valid parentheses substring is "()".
 *
 * Example 2:
 *
 * Input: s = ")()())"
 * Output: 4
 * Explanation: The longest valid parentheses substring is "()()".
 *
 * Example 3:
 *
 * Input: s = ""
 * Output: 0
 *
 *
 * Constraints:
 *
 * 0 <= s.length <= 3 * 10^4
 * s[i] is '(', or ')'.
 */

#ifndef LEETCODE_LONGEST_VALID_PARENTHESES_H
#define LEETCODE_LONGEST_VALID_PARENTHESES_H

int longestValidParentheses_32_1(char *s);

int longestValidParentheses_32_2(char *s);

int longestValidParentheses_32_3(char *s);

#endif //LEETCODE_LONGEST_VALID_PARENTHESES_H

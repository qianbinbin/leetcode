#ifndef LEETCODE_EVALUATE_REVERSE_POLISH_NOTATION_H
#define LEETCODE_EVALUATE_REVERSE_POLISH_NOTATION_H

/**
 * Evaluate the value of an arithmetic expression in Reverse Polish Notation (http://en.wikipedia.org/wiki/Reverse_Polish_notation).
 *
 * Valid operators are +, -, *, /. Each operand may be an integer or another expression.
 *
 * Some examples:
 *   ["2", "1", "+", "3", "*"] -> ((2 + 1) * 3) -> 9
 *   ["4", "13", "5", "/", "+"] -> (4 + (13 / 5)) -> 6
 */
int evalRPN_150(char **tokens, int tokensSize);

#endif //LEETCODE_EVALUATE_REVERSE_POLISH_NOTATION_H

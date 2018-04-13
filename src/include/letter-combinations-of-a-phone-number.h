#ifndef LEETCODE_LETTER_COMBINATIONS_OF_A_PHONE_NUMBER_H
#define LEETCODE_LETTER_COMBINATIONS_OF_A_PHONE_NUMBER_H

/**
 * Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent.
 *
 * A mapping of digit to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.
 *
 * http://upload.wikimedia.org/wikipedia/commons/thumb/7/73/Telephone-keypad2.svg/200px-Telephone-keypad2.svg.png
 *
 * Example:
 *
 * Input: "23"
 * Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
 * Note:
 *
 * Although the above answer is in lexicographical order, your answer could be in any order you want.
 *
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
char **letterCombinations_17(char *digits, int *returnSize);

#endif //LEETCODE_LETTER_COMBINATIONS_OF_A_PHONE_NUMBER_H

package io.binac.leetcode;

import java.util.ArrayList;
import java.util.List;

/**
 * Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent.
 * <p>
 * <p>A mapping of digit to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.
 * <p>
 * <p>http://upload.wikimedia.org/wikipedia/commons/thumb/7/73/Telephone-keypad2.svg/200px-Telephone-keypad2.svg.png
 * <p>
 * <p>Example:
 * <blockquote><pre>
 *     Input: "23"
 *     Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
 * </blockquote></pre>
 * Note:
 * <p>
 * <p>Although the above answer is in lexicographical order, your answer could be in any order you want.
 */
public class LetterCombinationsOfAPhoneNumber {
    public static class Solution1 {
        private static final String MAP[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

        public List<String> letterCombinations(String digits) {
            final int len = digits.length();
            List<String> result = new ArrayList<>();
            if (len == 0) return result;

            int dgt[] = new int[len];
            for (int i = 0; i < len; ++i) dgt[i] = digits.charAt(i) - '0';

            letterCombinations(dgt, 0, result, new StringBuilder());
            return result;
        }

        private void letterCombinations(int digits[], int index, List<String> result, StringBuilder path) {
            if (index == digits.length) {
                result.add(path.toString());
                return;
            }
            String letters = MAP[digits[index]];
            final int len = letters.length();
            for (int i = 0; i < len; ++i) {
                path.append(letters.charAt(i));
                letterCombinations(digits, index + 1, result, path);
                path.deleteCharAt(path.length() - 1);
            }
        }
    }
}

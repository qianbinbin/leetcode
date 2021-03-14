package io.binac.leetcode;

import java.util.ArrayList;
import java.util.List;

/**
 * <p>Given a string containing digits from <code>2-9</code> inclusive, return all possible letter combinations that the number could represent. Return the answer in <strong>any order</strong>.</p>
 *
 * <p>A mapping of digit to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.</p>
 *
 * <p><img src="https://upload.wikimedia.org/wikipedia/commons/thumb/7/73/Telephone-keypad2.svg/200px-Telephone-keypad2.svg.png" style="width: 200px; height: 162px;"></p>
 *
 * <p>&nbsp;</p>
 * <p><strong>Example 1:</strong></p>
 *
 * <pre><strong>Input:</strong> digits = "23"
 * <strong>Output:</strong> ["ad","ae","af","bd","be","bf","cd","ce","cf"]
 * </pre>
 *
 * <p><strong>Example 2:</strong></p>
 *
 * <pre><strong>Input:</strong> digits = ""
 * <strong>Output:</strong> []
 * </pre>
 *
 * <p><strong>Example 3:</strong></p>
 *
 * <pre><strong>Input:</strong> digits = "2"
 * <strong>Output:</strong> ["a","b","c"]
 * </pre>
 *
 * <p>&nbsp;</p>
 * <p><strong>Constraints:</strong></p>
 *
 * <ul>
 * 	<li><code>0 &lt;= digits.length &lt;= 4</code></li>
 * 	<li><code>digits[i]</code> is a digit in the range <code>['2', '9']</code>.</li>
 * </ul>
 */
public class LetterCombinationsOfAPhoneNumber {
    public static class Solution1 {
        private static final String[] MAP = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

        private void letterCombinations(String digits, int index, List<String> result, StringBuilder path) {
            if (index == digits.length()) {
                result.add(path.toString());
                return;
            }
            String letters = MAP[digits.charAt(index) - '0'];
            for (int i = 0, len = letters.length(); i < len; ++i) {
                path.append(letters.charAt(i));
                letterCombinations(digits, index + 1, result, path);
                path.deleteCharAt(path.length() - 1);
            }
        }

        public List<String> letterCombinations(String digits) {
            List<String> result = new ArrayList<>();
            if (digits.length() == 0)
                return result;

            letterCombinations(digits, 0, result, new StringBuilder());
            return result;
        }
    }
}

package io.binac.leetcode;

/**
 * <p>A phrase is a <strong>palindrome</strong> if, after converting all uppercase letters into lowercase letters and removing all non-alphanumeric characters, it reads the same forward and backward. Alphanumeric characters include letters and numbers.</p>
 *
 * <p>Given a string <code>s</code>, return <code>true</code><em> if it is a <strong>palindrome</strong>, or </em><code>false</code><em> otherwise</em>.</p>
 *
 * <p>&nbsp;</p>
 * <p><strong>Example 1:</strong></p>
 *
 * <pre><strong>Input:</strong> s = "A man, a plan, a canal: Panama"
 * <strong>Output:</strong> true
 * <strong>Explanation:</strong> "amanaplanacanalpanama" is a palindrome.
 * </pre>
 *
 * <p><strong>Example 2:</strong></p>
 *
 * <pre><strong>Input:</strong> s = "race a car"
 * <strong>Output:</strong> false
 * <strong>Explanation:</strong> "raceacar" is not a palindrome.
 * </pre>
 *
 * <p><strong>Example 3:</strong></p>
 *
 * <pre><strong>Input:</strong> s = " "
 * <strong>Output:</strong> true
 * <strong>Explanation:</strong> s is an empty string "" after removing non-alphanumeric characters.
 * Since an empty string reads the same forward and backward, it is a palindrome.
 * </pre>
 *
 * <p>&nbsp;</p>
 * <p><strong>Constraints:</strong></p>
 *
 * <ul>
 * 	<li><code>1 &lt;= s.length &lt;= 2 * 10<sup>5</sup></code></li>
 * 	<li><code>s</code> consists only of printable ASCII characters.</li>
 * </ul>
 */
public class ValidPalindrome {
    public static class Solution1 {
        public boolean isPalindrome(String s) {
            char[] str = s.toLowerCase().toCharArray();
            int i = 0, j = str.length - 1;
            while (i < j) {
                if (!Character.isLetterOrDigit(str[i])) {
                    ++i;
                } else if (!Character.isLetterOrDigit(str[j])) {
                    --j;
                } else if (str[i] != str[j]) {
                    return false;
                } else {
                    ++i;
                    --j;
                }
            }
            return true;
        }
    }
}

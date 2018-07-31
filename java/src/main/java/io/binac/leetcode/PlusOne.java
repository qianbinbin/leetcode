package io.binac.leetcode;

/**
 * Given a non-empty array of digits representing a non-negative integer, plus one to the integer.
 * <p>
 * <p>The digits are stored such that the most significant digit is at the head of the list, and each element in the array contain a single digit.
 * <p>
 * <p>You may assume the integer does not contain any leading zero, except the number 0 itself.
 * <p>
 * <p>Example 1:
 * <blockquote><pre>
 *     Input: [1,2,3]
 *     Output: [1,2,4]
 *     Explanation: The array represents the integer 123.
 * </blockquote></pre>
 * Example 2:
 * <blockquote><pre>
 *     Input: [4,3,2,1]
 *     Output: [4,3,2,2]
 *     Explanation: The array represents the integer 4321.
 * </blockquote></pre>
 */
public class PlusOne {
    public static class Solution1 {
        public int[] plusOne(int[] digits) {
            int result[] = new int[digits.length];
            System.arraycopy(digits, 0, result, 0, digits.length);
            for (int i = result.length - 1; i >= 0; --i) {
                if (result[i] == 9) {
                    result[i] = 0;
                } else {
                    ++result[i];
                    return result;
                }
            }
            result = new int[result.length + 1];
            result[0] = 1;
            return result;
        }
    }
}

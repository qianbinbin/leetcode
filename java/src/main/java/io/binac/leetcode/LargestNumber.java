package io.binac.leetcode;

import java.util.Arrays;

/**
 * <p>Given a list of non-negative integers <code>nums</code>, arrange them such that they form the largest number and return it.</p>
 *
 * <p>Since the result may be very large, so you need to return a string instead of an integer.</p>
 *
 * <p>&nbsp;</p>
 * <p><strong>Example 1:</strong></p>
 *
 * <pre><strong>Input:</strong> nums = [10,2]
 * <strong>Output:</strong> "210"
 * </pre>
 *
 * <p><strong>Example 2:</strong></p>
 *
 * <pre><strong>Input:</strong> nums = [3,30,34,5,9]
 * <strong>Output:</strong> "9534330"
 * </pre>
 *
 * <p>&nbsp;</p>
 * <p><strong>Constraints:</strong></p>
 *
 * <ul>
 * 	<li><code>1 &lt;= nums.length &lt;= 100</code></li>
 * 	<li><code>0 &lt;= nums[i] &lt;= 10<sup>9</sup></code></li>
 * </ul>
 */
public class LargestNumber {
    public static class Solution1 {
        public String largestNumber(int[] nums) {
            String[] strs = Arrays.stream(nums).mapToObj(String::valueOf).toArray(String[]::new);
            Arrays.sort(strs, (s1, s2) -> (int) (Long.parseLong(s2 + s1) - Long.parseLong(s1 + s2)));
            StringBuilder sb = new StringBuilder();
            Arrays.stream(strs).forEach(sb::append);
            return sb.charAt(0) == '0' ? "0" : sb.toString();
        }
    }
}

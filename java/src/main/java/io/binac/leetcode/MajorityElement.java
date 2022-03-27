package io.binac.leetcode;

/**
 * <p>Given an array <code>nums</code> of size <code>n</code>, return <em>the majority element</em>.</p>
 *
 * <p>The majority element is the element that appears more than <code>⌊n / 2⌋</code> times. You may assume that the majority element always exists in the array.</p>
 *
 * <p>&nbsp;</p>
 * <p><strong>Example 1:</strong></p>
 * <pre><strong>Input:</strong> nums = [3,2,3]
 * <strong>Output:</strong> 3
 * </pre><p><strong>Example 2:</strong></p>
 * <pre><strong>Input:</strong> nums = [2,2,1,1,1,2,2]
 * <strong>Output:</strong> 2
 * </pre>
 * <p>&nbsp;</p>
 * <p><strong>Constraints:</strong></p>
 *
 * <ul>
 * 	<li><code>n == nums.length</code></li>
 * 	<li><code>1 &lt;= n &lt;= 5 * 10<sup>4</sup></code></li>
 * 	<li><code>-2<sup>31</sup> &lt;= nums[i] &lt;= 2<sup>31</sup> - 1</code></li>
 * </ul>
 *
 * <p>&nbsp;</p>
 * <strong>Follow-up:</strong> Could you solve the problem in linear time and in <code>O(1)</code> space?
 */
public class MajorityElement {
    public static class Solution1 {
        public int majorityElement(int[] nums) {
            int result = nums[0];
            int count = 1;
            for (int i = 1; i < nums.length; ++i) {
                if (count == 0) {
                    result = nums[i];
                    count = 1;
                } else if (nums[i] == result) {
                    ++count;
                } else {
                    --count;
                }
            }
            return result;
        }
    }
}

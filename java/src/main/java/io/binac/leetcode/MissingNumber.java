package io.binac.leetcode;

/**
 * <p>Given an array <code>nums</code> containing <code>n</code> distinct numbers in the range <code>[0, n]</code>, return <em>the only number in the range that is missing from the array.</em></p>
 *
 * <p>&nbsp;</p>
 * <p><strong>Example 1:</strong></p>
 *
 * <pre><strong>Input:</strong> nums = [3,0,1]
 * <strong>Output:</strong> 2
 * <strong>Explanation:</strong> n = 3 since there are 3 numbers, so all numbers are in the range [0,3]. 2 is the missing number in the range since it does not appear in nums.
 * </pre>
 *
 * <p><strong>Example 2:</strong></p>
 *
 * <pre><strong>Input:</strong> nums = [0,1]
 * <strong>Output:</strong> 2
 * <strong>Explanation:</strong> n = 2 since there are 2 numbers, so all numbers are in the range [0,2]. 2 is the missing number in the range since it does not appear in nums.
 * </pre>
 *
 * <p><strong>Example 3:</strong></p>
 *
 * <pre><strong>Input:</strong> nums = [9,6,4,2,3,5,7,0,1]
 * <strong>Output:</strong> 8
 * <strong>Explanation:</strong> n = 9 since there are 9 numbers, so all numbers are in the range [0,9]. 8 is the missing number in the range since it does not appear in nums.
 * </pre>
 *
 * <p>&nbsp;</p>
 * <p><strong>Constraints:</strong></p>
 *
 * <ul>
 * 	<li><code>n == nums.length</code></li>
 * 	<li><code>1 &lt;= n &lt;= 10<sup>4</sup></code></li>
 * 	<li><code>0 &lt;= nums[i] &lt;= n</code></li>
 * 	<li>All the numbers of <code>nums</code> are <strong>unique</strong>.</li>
 * </ul>
 *
 * <p>&nbsp;</p>
 * <p><strong>Follow up:</strong> Could you implement a solution using only <code>O(1)</code> extra space complexity and <code>O(n)</code> runtime complexity?</p>
 */
public class MissingNumber {
    public static class Solution1 {
        public int missingNumber(int[] nums) {
            final int n = nums.length;
            for (int i = 0, j, tmp; i < n; ++i) {
                while ((j = nums[i]) != i && j < n && nums[j] != j) {
                    tmp = nums[i];
                    nums[i] = nums[j];
                    nums[j] = tmp;
                }
            }
            for (int i = 0; i < n; ++i) {
                if (nums[i] != i)
                    return i;
            }
            return n;
        }
    }

    public static class Solution2 {
        public int missingNumber(int[] nums) {
            final int n = nums.length;
            int result = 0;
            for (int i = 0; i < n; ++i)
                result ^= i ^ nums[i];
            result ^= n;
            return result;
        }
    }

    public static class Solution3 {
        public int missingNumber(int[] nums) {
            final int n = nums.length;
            int sum = n * (n + 1) / 2;
            for (int num : nums)
                sum -= num;
            return sum;
        }
    }
}

package io.binac.leetcode;

import java.util.Arrays;

/**
 * <p>Given an integer array <code>nums</code>, return the length of the longest strictly increasing subsequence.</p>
 *
 * <p>A <strong>subsequence</strong> is a sequence that can be derived from an array by deleting some or no elements without changing the order of the remaining elements. For example, <code>[3,6,2,7]</code> is a subsequence of the array <code>[0,3,1,6,2,2,7]</code>.</p>
 *
 * <p>&nbsp;</p>
 * <p><strong>Example 1:</strong></p>
 *
 * <pre><strong>Input:</strong> nums = [10,9,2,5,3,7,101,18]
 * <strong>Output:</strong> 4
 * <strong>Explanation:</strong> The longest increasing subsequence is [2,3,7,101], therefore the length is 4.
 * </pre>
 *
 * <p><strong>Example 2:</strong></p>
 *
 * <pre><strong>Input:</strong> nums = [0,1,0,3,2,3]
 * <strong>Output:</strong> 4
 * </pre>
 *
 * <p><strong>Example 3:</strong></p>
 *
 * <pre><strong>Input:</strong> nums = [7,7,7,7,7,7,7]
 * <strong>Output:</strong> 1
 * </pre>
 *
 * <p>&nbsp;</p>
 * <p><strong>Constraints:</strong></p>
 *
 * <ul>
 * 	<li><code>1 &lt;= nums.length &lt;= 2500</code></li>
 * 	<li><code>-10<sup>4</sup> &lt;= nums[i] &lt;= 10<sup>4</sup></code></li>
 * </ul>
 *
 * <p>&nbsp;</p>
 * <p><b>Follow up:</b>&nbsp;Can you come up with an algorithm that runs in&nbsp;<code>O(n log(n))</code> time complexity?</p>
 */
public class LongestIncreasingSubsequence {
    public static class Solution1 {
        public int lengthOfLIS(int[] nums) {
            final int n = nums.length;
            int[] dp = new int[n];
            Arrays.fill(dp, 1);
            int result = 1;
            for (int i = 1, j; i < n; ++i) {
                for (j = i - 1; j >= 0; --j) {
                    if (nums[j] < nums[i])
                        dp[i] = Math.max(dp[i], dp[j] + 1);
                }
                result = Math.max(result, dp[i]);
            }
            return result;
        }
    }

    public static class Solution2 {
        public int lengthOfLIS(int[] nums) {
            int[] dp = new int[nums.length];
            int size = 0;
            int i;
            for (int num : nums) {
                i = Arrays.binarySearch(dp, 0, size, num);
                if (i >= 0)
                    continue;
                if (i == -size - 1)
                    dp[size++] = num;
                else
                    dp[-i - 1] = num;
            }
            return size;
        }
    }
}

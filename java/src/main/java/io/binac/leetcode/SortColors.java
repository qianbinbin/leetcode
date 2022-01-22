package io.binac.leetcode;

import java.util.Arrays;

/**
 * <p>Given an array <code>nums</code> with <code>n</code> objects colored red, white, or blue, sort them <strong><a href="https://en.wikipedia.org/wiki/In-place_algorithm" target="_blank">in-place</a> </strong>so that objects of the same color are adjacent, with the colors in the order red, white, and blue.</p>
 *
 * <p>We will use the integers <code>0</code>, <code>1</code>, and <code>2</code> to represent the color red, white, and blue, respectively.</p>
 *
 * <p>You must solve this problem without using the library's sort function.</p>
 *
 * <p>&nbsp;</p>
 * <p><strong>Example 1:</strong></p>
 *
 * <pre><strong>Input:</strong> nums = [2,0,2,1,1,0]
 * <strong>Output:</strong> [0,0,1,1,2,2]
 * </pre>
 *
 * <p><strong>Example 2:</strong></p>
 *
 * <pre><strong>Input:</strong> nums = [2,0,1]
 * <strong>Output:</strong> [0,1,2]
 * </pre>
 *
 * <p>&nbsp;</p>
 * <p><strong>Constraints:</strong></p>
 *
 * <ul>
 * 	<li><code>n == nums.length</code></li>
 * 	<li><code>1 &lt;= n &lt;= 300</code></li>
 * 	<li><code>nums[i]</code> is either <code>0</code>, <code>1</code>, or <code>2</code>.</li>
 * </ul>
 *
 * <p>&nbsp;</p>
 * <p><strong>Follow up:</strong>&nbsp;Could you come up with a one-pass algorithm using only&nbsp;constant extra space?</p>
 */
public class SortColors {
    public static class Solution1 {
        public void sortColors(int[] nums) {
            int count0 = 0, count1 = 0;
            for (int num : nums) {
                if (num == 0)
                    ++count0;
                else if (num == 1)
                    ++count1;
            }
            Arrays.fill(nums, 0, count0, 0);
            Arrays.fill(nums, count0, count0 + count1, 1);
            Arrays.fill(nums, count0 + count1, nums.length, 2);
        }
    }

    public static class Solution2 {
        private void swap(int[] x, int a, int b) {
            int t = x[a];
            x[a] = x[b];
            x[b] = t;
        }

        public void sortColors(int[] nums) {
            int last0 = -1, first2 = nums.length;
            for (int i = 0; i < first2; ) {
                if (nums[i] == 0)
                    swap(nums, ++last0, i++);
                else if (nums[i] == 2)
                    swap(nums, i, --first2);
                else
                    ++i;
            }
        }
    }
}

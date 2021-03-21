package io.binac.leetcode;

import java.util.Arrays;

/**
 * <p>Implement <strong>next permutation</strong>, which rearranges numbers into the lexicographically next greater permutation of numbers.</p>
 *
 * <p>If such an arrangement is not possible, it must rearrange it as the lowest possible order (i.e., sorted in ascending order).</p>
 *
 * <p>The replacement must be <strong><a href="http://en.wikipedia.org/wiki/In-place_algorithm" target="_blank">in place</a></strong> and use only constant&nbsp;extra memory.</p>
 *
 * <p>&nbsp;</p>
 * <p><strong>Example 1:</strong></p>
 * <pre><strong>Input:</strong> nums = [1,2,3]
 * <strong>Output:</strong> [1,3,2]
 * </pre><p><strong>Example 2:</strong></p>
 * <pre><strong>Input:</strong> nums = [3,2,1]
 * <strong>Output:</strong> [1,2,3]
 * </pre><p><strong>Example 3:</strong></p>
 * <pre><strong>Input:</strong> nums = [1,1,5]
 * <strong>Output:</strong> [1,5,1]
 * </pre><p><strong>Example 4:</strong></p>
 * <pre><strong>Input:</strong> nums = [1]
 * <strong>Output:</strong> [1]
 * </pre>
 * <p>&nbsp;</p>
 * <p><strong>Constraints:</strong></p>
 *
 * <ul>
 * 	<li><code>1 &lt;= nums.length &lt;= 100</code></li>
 * 	<li><code>0 &lt;= nums[i] &lt;= 100</code></li>
 * </ul>
 */
public class NextPermutation {
    public static class Solution1 {
        private void reverse(int[] array, int beginIndex, int endIndex) {
            final int sum = beginIndex + endIndex;
            final int half = sum >>> 1;
            int tmp, i, j;
            for (i = beginIndex; i < half; ++i) {
                j = sum - 1 - i;
                tmp = array[i];
                array[i] = array[j];
                array[j] = tmp;
            }
        }

        public void nextPermutation(int[] nums) {
            int i = nums.length - 2;
            while (i >= 0 && nums[i] >= nums[i + 1]) --i;
            if (i >= 0) {
                int j = nums.length - 1;
                while (j > i && nums[j] <= nums[i]) --j;
                int tmp = nums[i];
                nums[i] = nums[j];
                nums[j] = tmp;
            }
            reverse(nums, i + 1, nums.length);
        }
    }
}

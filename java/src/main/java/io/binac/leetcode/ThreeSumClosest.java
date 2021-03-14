package io.binac.leetcode;

import java.util.Arrays;

/**
 * <p>Given an array <code>nums</code> of <em>n</em> integers and an integer <code>target</code>, find three integers in <code>nums</code>&nbsp;such that the sum is closest to&nbsp;<code>target</code>. Return the sum of the three integers. You may assume that each input would have exactly one solution.</p>
 *
 * <p>&nbsp;</p>
 * <p><strong>Example 1:</strong></p>
 *
 * <pre><strong>Input:</strong> nums = [-1,2,1,-4], target = 1
 * <strong>Output:</strong> 2
 * <strong>Explanation:</strong> The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
 * </pre>
 *
 * <p>&nbsp;</p>
 * <p><strong>Constraints:</strong></p>
 *
 * <ul>
 * 	<li><code>3 &lt;= nums.length &lt;= 10^3</code></li>
 * 	<li><code>-10^3&nbsp;&lt;= nums[i]&nbsp;&lt;= 10^3</code></li>
 * 	<li><code>-10^4&nbsp;&lt;= target&nbsp;&lt;= 10^4</code></li>
 * </ul>
 */
public class ThreeSumClosest {
    public static class Solution1 {
        public int threeSumClosest(int[] nums, int target) {
            Arrays.sort(nums);
            int result = nums[0] + nums[1] + nums[2], sum;
            for (int i = 0, j, k, e = nums.length - 2; i < e; ) {
                j = i + 1;
                k = nums.length - 1;
                while (j < k) {
                    sum = nums[i] + nums[j] + nums[k];
                    if (Math.abs(sum - target) < Math.abs(result - target))
                        result = sum;
                    if (sum < target) {
                        do {
                            ++j;
                        } while (j < k && nums[j] == nums[j - 1]);
                    } else if (sum > target) {
                        do {
                            --k;
                        } while (k > j && nums[k] == nums[k + 1]);
                    } else {
                        return result;
                    }
                }
                do {
                    ++i;
                } while (i < e && nums[i] == nums[i - 1]);
            }
            return result;
        }
    }
}

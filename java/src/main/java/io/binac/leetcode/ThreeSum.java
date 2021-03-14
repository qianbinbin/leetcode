package io.binac.leetcode;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.List;

/**
 * <p>Given an array <code>nums</code> of <em>n</em> integers, are there elements <em>a</em>, <em>b</em>, <em>c</em> in <code>nums</code> such that <em>a</em> + <em>b</em> + <em>c</em> = 0? Find all unique triplets in the array which gives the sum of zero.</p>
 *
 * <p>Notice that the solution set must not contain duplicate triplets.</p>
 *
 * <p>&nbsp;</p>
 * <p><strong>Example 1:</strong></p>
 * <pre><strong>Input:</strong> nums = [-1,0,1,2,-1,-4]
 * <strong>Output:</strong> [[-1,-1,2],[-1,0,1]]
 * </pre><p><strong>Example 2:</strong></p>
 * <pre><strong>Input:</strong> nums = []
 * <strong>Output:</strong> []
 * </pre><p><strong>Example 3:</strong></p>
 * <pre><strong>Input:</strong> nums = [0]
 * <strong>Output:</strong> []
 * </pre>
 * <p>&nbsp;</p>
 * <p><strong>Constraints:</strong></p>
 *
 * <ul>
 * 	<li><code>0 &lt;= nums.length &lt;= 3000</code></li>
 * 	<li><code>-10<sup>5</sup> &lt;= nums[i] &lt;= 10<sup>5</sup></code></li>
 * </ul>
 */
public class ThreeSum {
    public static class Solution1 {
        public List<List<Integer>> threeSum(int[] nums) {
            List<List<Integer>> result = new ArrayList<>();
            if (nums.length < 3)
                return result;

            Arrays.sort(nums);

            for (int i = 0, j, k, e = nums.length - 2, sum; i < e; ) {
                sum = -nums[i];
                j = i + 1;
                k = nums.length - 1;
                while (j < k) {
                    if (nums[j] + nums[k] < sum) {
                        do {
                            ++j;
                        } while (j < k && nums[j] == nums[j - 1]);
                    } else if (nums[j] + nums[k] > sum) {
                        do {
                            --k;
                        } while (k > j && nums[k] == nums[k + 1]);
                    } else {
                        result.add(Arrays.asList(nums[i], nums[j], nums[k]));
                        do {
                            ++j;
                        } while (j < k && nums[j] == nums[j - 1]);
                        do {
                            --k;
                        } while (k > j && nums[k] == nums[k + 1]);
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

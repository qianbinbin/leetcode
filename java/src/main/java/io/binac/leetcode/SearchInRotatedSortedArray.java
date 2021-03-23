package io.binac.leetcode;

/**
 * <p>You are given an integer array <code>nums</code> sorted in ascending order (with <strong>distinct</strong> values), and an integer <code>target</code>.</p>
 *
 * <p>Suppose that <code>nums</code> is rotated at some pivot unknown to you beforehand (i.e., <code>[0,1,2,4,5,6,7]</code> might become <code>[4,5,6,7,0,1,2]</code>).</p>
 *
 * <p><em>If <code>target</code> is found in the array return its index, otherwise, return <code>-1</code>.</em></p>
 *
 * <p>&nbsp;</p>
 * <p><strong>Example 1:</strong></p>
 * <pre><strong>Input:</strong> nums = [4,5,6,7,0,1,2], target = 0
 * <strong>Output:</strong> 4
 * </pre><p><strong>Example 2:</strong></p>
 * <pre><strong>Input:</strong> nums = [4,5,6,7,0,1,2], target = 3
 * <strong>Output:</strong> -1
 * </pre><p><strong>Example 3:</strong></p>
 * <pre><strong>Input:</strong> nums = [1], target = 0
 * <strong>Output:</strong> -1
 * </pre>
 * <p>&nbsp;</p>
 * <p><strong>Constraints:</strong></p>
 *
 * <ul>
 * 	<li><code>1 &lt;= nums.length &lt;= 5000</code></li>
 * 	<li><code>-10<sup>4</sup> &lt;= nums[i] &lt;= 10<sup>4</sup></code></li>
 * 	<li>All values of <code>nums</code> are <strong>unique</strong>.</li>
 * 	<li><code>nums</code> is guaranteed to be rotated at some pivot.</li>
 * 	<li><code>-10<sup>4</sup> &lt;= target &lt;= 10<sup>4</sup></code></li>
 * </ul>
 */
public class SearchInRotatedSortedArray {
    public static class Solution1 {
        public int search(int[] nums, int target) {
            int low = 0, high = nums.length - 1, mid;
            while (low <= high) {
                mid = (low + high) >>> 1;
                if (nums[mid] == target)
                    return mid;
                if (nums[low] <= nums[mid]) {
                    if (nums[low] <= target && target < nums[mid])
                        high = mid - 1;
                    else
                        low = mid + 1;
                } else {
                    if (nums[mid] < target && target <= nums[high])
                        low = mid + 1;
                    else
                        high = mid - 1;
                }
            }
            return -1;
        }
    }
}

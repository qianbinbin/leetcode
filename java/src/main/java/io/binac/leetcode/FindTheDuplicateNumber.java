package io.binac.leetcode;

/**
 * <p>Given an array of integers <code>nums</code> containing&nbsp;<code>n + 1</code> integers where each integer is in the range <code>[1, n]</code> inclusive.</p>
 *
 * <p>There is only <strong>one repeated number</strong> in <code>nums</code>, return <em>this&nbsp;repeated&nbsp;number</em>.</p>
 *
 * <p>You must solve the problem <strong>without</strong> modifying the array <code>nums</code>&nbsp;and uses only constant extra space.</p>
 *
 * <p>&nbsp;</p>
 * <p><strong>Example 1:</strong></p>
 *
 * <pre><strong>Input:</strong> nums = [1,3,4,2,2]
 * <strong>Output:</strong> 2
 * </pre>
 *
 * <p><strong>Example 2:</strong></p>
 *
 * <pre><strong>Input:</strong> nums = [3,1,3,4,2]
 * <strong>Output:</strong> 3
 * </pre>
 *
 * <p>&nbsp;</p>
 * <p><strong>Constraints:</strong></p>
 *
 * <ul>
 * 	<li><code>1 &lt;= n &lt;= 10<sup>5</sup></code></li>
 * 	<li><code>nums.length == n + 1</code></li>
 * 	<li><code>1 &lt;= nums[i] &lt;= n</code></li>
 * 	<li>All the integers in <code>nums</code> appear only <strong>once</strong> except for <strong>precisely one integer</strong> which appears <strong>two or more</strong> times.</li>
 * </ul>
 *
 * <p>&nbsp;</p>
 * <p><b>Follow up:</b></p>
 *
 * <ul>
 * 	<li>How can we prove that at least one duplicate number must exist in <code>nums</code>?</li>
 * 	<li>Can you solve the problem in linear runtime complexity?</li>
 * </ul>
 */
public class FindTheDuplicateNumber {
    public static class Solution1 {
        public int findDuplicate(int[] nums) {
            int low = 1, high = nums.length - 1, mid;
            int count;
            while (low <= high) {
                mid = (low + high) >>> 1;
                count = 0;
                for (int n : nums) {
                    if (n <= mid)
                        ++count;
                }
                if (count <= mid)
                    low = mid + 1;
                else
                    high = mid - 1;
            }
            return low;
        }
    }

    public static class Solution2 {
        public int findDuplicate(int[] nums) {
            final int n = nums.length - 1;
            int highest = 0;
            while (n >>> highest != 0)
                ++highest;
            int result = 0;
            for (int bit = 0, mask, i, expected, actual; bit < highest; ++bit) {
                mask = 1 << bit;
                expected = actual = 0;
                for (i = 0; i <= n; ++i) {
                    if ((i & mask) != 0)
                        ++expected;
                    if ((nums[i] & mask) != 0)
                        ++actual;
                }
                if (expected < actual)
                    result |= mask;
            }
            return result;
        }
    }

    public static class Solution3 {
        public int findDuplicate(int[] nums) {
            int slow = 0, fast = 0;
            do {
                slow = nums[slow];
                fast = nums[nums[fast]];
            } while (slow != fast);
            int n = 0;
            while (n != slow) {
                n = nums[n];
                slow = nums[slow];
            }
            return n;
        }
    }
}

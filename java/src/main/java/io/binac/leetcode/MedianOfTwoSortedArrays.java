package io.binac.leetcode;

/**
 * <p>Given two sorted arrays <code>nums1</code> and <code>nums2</code> of size <code>m</code> and <code>n</code> respectively, return <strong>the median</strong> of the two sorted arrays.</p>
 * <p><strong>Follow up:</strong> The overall run time complexity should be <code>O(log (m+n))</code>.</p>
 * <p>&nbsp;</p>
 * <p><strong>Example 1:</strong></p>
 * <pre><strong>Input:</strong> nums1 = [1,3], nums2 = [2]
 * <strong>Output:</strong> 2.00000
 * <strong>Explanation:</strong> merged array = [1,2,3] and median is 2.
 * </pre>
 * <p><strong>Example 2:</strong></p>
 * <pre><strong>Input:</strong> nums1 = [1,2], nums2 = [3,4]
 * <strong>Output:</strong> 2.50000
 * <strong>Explanation:</strong> merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.
 * </pre>
 * <p><strong>Example 3:</strong></p>
 * <pre><strong>Input:</strong> nums1 = [0,0], nums2 = [0,0]
 * <strong>Output:</strong> 0.00000
 * </pre>
 * <p><strong>Example 4:</strong></p>
 * <pre><strong>Input:</strong> nums1 = [], nums2 = [1]
 * <strong>Output:</strong> 1.00000
 * </pre>
 * <p><strong>Example 5:</strong></p>
 * <pre><strong>Input:</strong> nums1 = [2], nums2 = []
 * <strong>Output:</strong> 2.00000
 * </pre>
 * <p>&nbsp;</p>
 * <p><strong>Constraints:</strong></p>
 * <ul>
 * <li><code>nums1.length == m</code></li>
 * <li><code>nums2.length == n</code></li>
 * <li><code>0 &lt;= m &lt;= 1000</code></li>
 * <li><code>0 &lt;= n &lt;= 1000</code></li>
 * <li><code>1 &lt;= m + n &lt;= 2000</code></li>
 * <li><code>-10<sup>6</sup> &lt;= nums1[i], nums2[i] &lt;= 10<sup>6</sup></code></li>
 * </ul>
 */
public class MedianOfTwoSortedArrays {
    public static class Solution1 {
        public double findMedianSortedArrays(int[] nums1, int[] nums2) {
            if (nums1.length > nums2.length) {
                int[] tmp = nums1;
                nums1 = nums2;
                nums2 = tmp;
            }

            final int m = nums1.length, n = nums2.length, sum = (m + n + 1) >>> 1;
            int low = 0, high = m, i = 0, j = 0;
            while (low <= high) {
                i = (low + high) >>> 1;
                j = sum - i;
                if (i > 0 && j < n && nums1[i - 1] > nums2[j])
                    high = i - 1;
                else if (i < m && j > 0 && nums2[j - 1] > nums1[i])
                    low = i + 1;
                else
                    break;
            }

            int left;
            if (i == 0)
                left = nums2[j - 1];
            else if (j == 0)
                left = nums1[i - 1];
            else
                left = Math.max(nums1[i - 1], nums2[j - 1]);

            if ((m + n) % 2 != 0)
                return left;

            int right;
            if (i == m)
                right = nums2[j];
            else if (j == n)
                right = nums1[i];
            else
                right = Math.min(nums1[i], nums2[j]);
            return (left + right) / 2.0;
        }
    }
}

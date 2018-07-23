package io.binac.leetcode;

import java.util.HashSet;
import java.util.Set;

/**
 * Given an unsorted array of integers, find the length of the longest consecutive elements sequence.
 * <p>
 * <p>Your algorithm should run in O(n) complexity.
 * <p>
 * <p>Example:
 * <blockquote><pre>
 *     Input: [100, 4, 200, 1, 3, 2]
 *     Output: 4
 *     Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.
 * </blockquote></pre>
 */
public class LongestConsecutiveSequence {
    public static class Solution1 {
        public int longestConsecutive(int[] nums) {
            if (nums.length == 0) return 0;

            Set<Integer> set = new HashSet<>();
            for (int num : nums) set.add(num);
            int result = 1;
            for (int num : nums) {
                if (!set.contains(num - 1)) {
                    int n = num + 1;
                    while (set.contains(n)) ++n;
                    result = Math.max(result, n - num);
                }
            }
            return result;
        }
    }
}

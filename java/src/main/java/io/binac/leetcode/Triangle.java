package io.binac.leetcode;

import java.util.List;

/**
 * Given a triangle, find the minimum path sum from top to bottom. Each step you may move to adjacent numbers on the row below.
 * <p>
 * <p>For example, given the following triangle
 * <blockquote><pre>
 *     [
 *          [2],
 *         [3,4],
 *        [6,5,7],
 *       [4,1,8,3]
 *     ]
 * </blockquote></pre>
 * The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).
 * <p>
 * <p>Note:
 * <p>
 * <p>Bonus point if you are able to do this using only O(n) extra space, where n is the total number of rows in the triangle.
 */
public class Triangle {
    public static class Solution1 {
        public int minimumTotal(List<List<Integer>> triangle) {
            final int size = triangle.size();
            if (size == 0) return 0;

            int dp[] = new int[size];
            List<Integer> last = triangle.get(size - 1);
            for (int i = 0; i < size; ++i) dp[i] = last.get(i);
            for (int i = size - 2; i >= 0; --i) {
                List<Integer> row = triangle.get(i);
                for (int j = 0; j <= i; ++j)
                    dp[j] = Math.min(dp[j], dp[j + 1]) + row.get(j);
            }
            return dp[0];
        }
    }
}

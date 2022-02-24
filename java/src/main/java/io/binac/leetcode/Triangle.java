package io.binac.leetcode;

import java.util.List;

/**
 * <p>Given a <code>triangle</code> array, return <em>the minimum path sum from top to bottom</em>.</p>
 *
 * <p>For each step, you may move to an adjacent number of the row below. More formally, if you are on index <code>i</code> on the current row, you may move to either index <code>i</code> or index <code>i + 1</code> on the next row.</p>
 *
 * <p>&nbsp;</p>
 * <p><strong>Example 1:</strong></p>
 *
 * <pre><strong>Input:</strong> triangle = [[2],[3,4],[6,5,7],[4,1,8,3]]
 * <strong>Output:</strong> 11
 * <strong>Explanation:</strong> The triangle looks like:
 *    <u>2</u>
 *   <u>3</u> 4
 *  6 <u>5</u> 7
 * 4 <u>1</u> 8 3
 * The minimum path sum from top to bottom is 2 + 3 + 5 + 1 = 11 (underlined above).
 * </pre>
 *
 * <p><strong>Example 2:</strong></p>
 *
 * <pre><strong>Input:</strong> triangle = [[-10]]
 * <strong>Output:</strong> -10
 * </pre>
 *
 * <p>&nbsp;</p>
 * <p><strong>Constraints:</strong></p>
 *
 * <ul>
 * 	<li><code>1 &lt;= triangle.length &lt;= 200</code></li>
 * 	<li><code>triangle[0].length == 1</code></li>
 * 	<li><code>triangle[i].length == triangle[i - 1].length + 1</code></li>
 * 	<li><code>-10<sup>4</sup> &lt;= triangle[i][j] &lt;= 10<sup>4</sup></code></li>
 * </ul>
 *
 * <p>&nbsp;</p>
 * <strong>Follow up:</strong> Could you&nbsp;do this using only <code>O(n)</code> extra space, where <code>n</code> is the total number of rows in the triangle?
 */
public class Triangle {
    public static class Solution1 {
        public int minimumTotal(List<List<Integer>> triangle) {
            final int n = triangle.size();
            int[] dp = new int[n];
            List<Integer> last = triangle.get(n - 1);
            for (int i = 0; i < n; ++i) dp[i] = last.get(i);
            for (int i = n - 2; i >= 0; --i) {
                List<Integer> row = triangle.get(i);
                for (int j = 0; j <= i; ++j)
                    dp[j] = Math.min(dp[j], dp[j + 1]) + row.get(j);
            }
            return dp[0];
        }
    }
}

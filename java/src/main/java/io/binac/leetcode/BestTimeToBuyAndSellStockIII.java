package io.binac.leetcode;

/**
 * <p>You are given an array <code>prices</code> where <code>prices[i]</code> is the price of a given stock on the <code>i<sup>th</sup></code> day.</p>
 *
 * <p>Find the maximum profit you can achieve. You may complete <strong>at most two transactions</strong>.</p>
 *
 * <p><strong>Note:</strong> You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).</p>
 *
 * <p>&nbsp;</p>
 * <p><strong>Example 1:</strong></p>
 *
 * <pre><strong>Input:</strong> prices = [3,3,5,0,0,3,1,4]
 * <strong>Output:</strong> 6
 * <strong>Explanation:</strong> Buy on day 4 (price = 0) and sell on day 6 (price = 3), profit = 3-0 = 3.
 * Then buy on day 7 (price = 1) and sell on day 8 (price = 4), profit = 4-1 = 3.</pre>
 *
 * <p><strong>Example 2:</strong></p>
 *
 * <pre><strong>Input:</strong> prices = [1,2,3,4,5]
 * <strong>Output:</strong> 4
 * <strong>Explanation:</strong> Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit = 5-1 = 4.
 * Note that you cannot buy on day 1, buy on day 2 and sell them later, as you are engaging multiple transactions at the same time. You must sell before buying again.
 * </pre>
 *
 * <p><strong>Example 3:</strong></p>
 *
 * <pre><strong>Input:</strong> prices = [7,6,4,3,1]
 * <strong>Output:</strong> 0
 * <strong>Explanation:</strong> In this case, no transaction is done, i.e. max profit = 0.
 * </pre>
 *
 * <p>&nbsp;</p>
 * <p><strong>Constraints:</strong></p>
 *
 * <ul>
 * 	<li><code>1 &lt;= prices.length &lt;= 10<sup>5</sup></code></li>
 * 	<li><code>0 &lt;= prices[i] &lt;= 10<sup>5</sup></code></li>
 * </ul>
 */
public class BestTimeToBuyAndSellStockIII {
    public static class Solution1 {
        public int maxProfit(int[] prices) {
            int hold1 = Integer.MIN_VALUE, release1 = 0, hold2 = Integer.MIN_VALUE, release2 = 0;
            for (int price : prices) {
                release2 = Math.max(release2, price + hold2);
                hold2 = Math.max(hold2, release1 - price);
                release1 = Math.max(release1, price + hold1);
                hold1 = Math.max(hold1, -price);
            }
            return release2;
        }
    }

    public static class Solution2 {
        public int maxProfit(int[] prices) {
            final int size = prices.length;

            int[] dp1 = new int[size];
            int valley = prices[0];
            for (int i = 1; i < size; ++i) {
                dp1[i] = Math.max(dp1[i - 1], prices[i] - valley);
                valley = Math.min(valley, prices[i]);
            }

            int[] dp2 = new int[size];
            int peak = prices[size - 1];
            for (int i = size - 2; i >= 0; --i) {
                dp2[i] = Math.max(dp2[i + 1], peak - prices[i]);
                peak = Math.max(peak, prices[i]);
            }

            int result = 0;
            for (int i = 0; i < size; ++i)
                result = Math.max(result, dp1[i] + dp2[i]);
            return result;
        }
    }
}

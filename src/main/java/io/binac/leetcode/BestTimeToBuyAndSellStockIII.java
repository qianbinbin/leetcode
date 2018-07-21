package io.binac.leetcode;

/**
 * Say you have an array for which the ith element is the price of a given stock on day i.
 * <p>
 * <p>Design an algorithm to find the maximum profit. You may complete at most two transactions.
 * <p>
 * <p>Note: You may not engage in multiple transactions at the same time (i.e., you must sell the stock before you buy again).
 * <p>
 * <p>Example 1:
 * <blockquote><pre>
 *     Input: [3,3,5,0,0,3,1,4]
 *     Output: 6
 *     Explanation: Buy on day 4 (price = 0) and sell on day 6 (price = 3), profit = 3-0 = 3.
 *                  Then buy on day 7 (price = 1) and sell on day 8 (price = 4), profit = 4-1 = 3.
 * </blockquote></pre>
 * Example 2:
 * <blockquote><pre>
 *     Input: [1,2,3,4,5]
 *     Output: 4
 *     Explanation: Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit = 5-1 = 4.
 *                  Note that you cannot buy on day 1, buy on day 2 and sell them later, as you are
 *                  engaging multiple transactions at the same time. You must sell before buying again.
 * </blockquote></pre>
 * Example 3:
 * <blockquote><pre>
 *     Input: [7,6,4,3,1]
 *     Output: 0
 *     Explanation: In this case, no transaction is done, i.e. max profit = 0.
 * </blockquote></pre>
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
}

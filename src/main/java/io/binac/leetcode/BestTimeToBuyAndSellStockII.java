package io.binac.leetcode;

/**
 * Say you have an array for which the ith element is the price of a given stock on day i.
 * <p>
 * <p>Design an algorithm to find the maximum profit. You may complete as many transactions as you like (i.e., buy one and sell one share of the stock multiple times).
 * <p>
 * <p>Note: You may not engage in multiple transactions at the same time (i.e., you must sell the stock before you buy again).
 * <p>
 * <p>Example 1:
 * <blockquote><pre>
 *     Input: [7,1,5,3,6,4]
 *     Output: 7
 *     Explanation: Buy on day 2 (price = 1) and sell on day 3 (price = 5), profit = 5-1 = 4.
 *                  Then buy on day 4 (price = 3) and sell on day 5 (price = 6), profit = 6-3 = 3.
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
public class BestTimeToBuyAndSellStockII {
    public static class Solution1 {
        public int maxProfit(int[] prices) {
            int result = 0;
            int valley;
            int i = 1;
            while (i < prices.length) {
                while (i < prices.length && prices[i] <= prices[i - 1]) ++i;
                valley = prices[i - 1];
                while (i < prices.length && prices[i] >= prices[i - 1]) ++i;
                result += prices[i - 1] - valley;
            }
            return result;
        }
    }
}

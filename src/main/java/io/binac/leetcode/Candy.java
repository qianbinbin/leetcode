package io.binac.leetcode;

import java.util.Arrays;

/**
 * There are N children standing in a line. Each child is assigned a rating value.
 * <p>
 * <p>You are giving candies to these children subjected to the following requirements:
 * <p>
 * <p>Each child must have at least one candy.
 * <p>Children with a higher rating get more candies than their neighbors.
 * <p>
 * <p>What is the minimum candies you must give?
 * <p>
 * <p>Example 1:
 * <blockquote><pre>
 *     Input: [1,0,2]
 *     Output: 5
 *     Explanation: You can allocate to the first, second and third child with 2, 1, 2 candies respectively.
 * </blockquote></pre>
 * Example 2:
 * <blockquote><pre>
 *     Input: [1,2,2]
 *     Output: 4
 *     Explanation: You can allocate to the first, second and third child with 1, 2, 1 candies respectively.
 *                  The third child gets 1 candy because it satisfies the above two conditions.
 * </blockquote></pre>
 */
public class Candy {
    public static class Solution1 {
        public int candy(int[] ratings) {
            if (ratings.length == 0) return 0;

            int candy[] = new int[ratings.length];
            Arrays.fill(candy, 1);
            for (int i = 1; i < ratings.length; ++i) {
                if (ratings[i] > ratings[i - 1])
                    candy[i] = candy[i - 1] + 1;
            }
            int result = candy[ratings.length - 1];
            for (int i = ratings.length - 2; i >= 0; --i) {
                if (ratings[i] > ratings[i + 1])
                    candy[i] = Math.max(candy[i], candy[i + 1] + 1);
                result += candy[i];
            }
            return result;
        }
    }
}

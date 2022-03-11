package io.binac.leetcode;

import java.util.Arrays;

/**
 * <p>There are <code>n</code> children standing in a line. Each child is assigned a rating value given in the integer array <code>ratings</code>.</p>
 *
 * <p>You are giving candies to these children subjected to the following requirements:</p>
 *
 * <ul>
 * 	<li>Each child must have at least one candy.</li>
 * 	<li>Children with a higher rating get more candies than their neighbors.</li>
 * </ul>
 *
 * <p>Return <em>the minimum number of candies you need to have to distribute the candies to the children</em>.</p>
 *
 * <p>&nbsp;</p>
 * <p><strong>Example 1:</strong></p>
 *
 * <pre><strong>Input:</strong> ratings = [1,0,2]
 * <strong>Output:</strong> 5
 * <strong>Explanation:</strong> You can allocate to the first, second and third child with 2, 1, 2 candies respectively.
 * </pre>
 *
 * <p><strong>Example 2:</strong></p>
 *
 * <pre><strong>Input:</strong> ratings = [1,2,2]
 * <strong>Output:</strong> 4
 * <strong>Explanation:</strong> You can allocate to the first, second and third child with 1, 2, 1 candies respectively.
 * The third child gets 1 candy because it satisfies the above two conditions.
 * </pre>
 *
 * <p>&nbsp;</p>
 * <p><strong>Constraints:</strong></p>
 *
 * <ul>
 * 	<li><code>n == ratings.length</code></li>
 * 	<li><code>1 &lt;= n &lt;= 2 * 10<sup>4</sup></code></li>
 * 	<li><code>0 &lt;= ratings[i] &lt;= 2 * 10<sup>4</sup></code></li>
 * </ul>
 */
public class Candy {
    public static class Solution1 {
        public int candy(int[] ratings) {
            int[] candies = new int[ratings.length];
            Arrays.fill(candies, 1);
            for (int i = 1; i < ratings.length; ++i) {
                if (ratings[i] > ratings[i - 1])
                    candies[i] = candies[i - 1] + 1;
            }
            int result = candies[ratings.length - 1];
            for (int i = ratings.length - 2; i >= 0; --i) {
                if (ratings[i] > ratings[i + 1])
                    candies[i] = Math.max(candies[i], candies[i + 1] + 1);
                result += candies[i];
            }
            return result;
        }
    }
}

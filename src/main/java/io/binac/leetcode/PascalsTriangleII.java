package io.binac.leetcode;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.List;
import java.util.stream.Collectors;

/**
 * Given a non-negative index k where k ≤ 33, return the kth index row of the Pascal's triangle.
 * <p>
 * <p>Note that the row index starts from 0.
 * <p>
 * <p>https://upload.wikimedia.org/wikipedia/commons/0/0d/PascalTriangleAnimated2.gif
 * <p>
 * <p>In Pascal's triangle, each number is the sum of the two numbers directly above it.
 * <p>
 * <p>Example:
 * <blockquote><pre>
 *     Input: 3
 *     Output: [1,3,3,1]
 * </blockquote></pre>
 * Follow up:
 * <p>
 * <p>Could you optimize your algorithm to use only O(k) extra space?
 */
public class PascalsTriangleII {
    public static class Solution1 {
        public List<Integer> getRow(int rowIndex) {
            if (rowIndex < 0)
                throw new IllegalArgumentException("rowIndex must be non-negative");
            List<Integer> result = new ArrayList<>(rowIndex + 1);
            result.add(1);
            for (int i = 1; i <= rowIndex; ++i) {
                result.add(1);
                for (int j = i - 1; j > 0; --j)
                    result.set(j, result.get(j) + result.get(j - 1));
            }
            return result;
        }
    }
}

package io.binac.leetcode;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.List;

/**
 * Given a non-negative integer numRows, generate the first numRows of Pascal's triangle.
 * <p>
 * <p>https://upload.wikimedia.org/wikipedia/commons/0/0d/PascalTriangleAnimated2.gif
 * <p>
 * <p>In Pascal's triangle, each number is the sum of the two numbers directly above it.
 * <p>
 * <p>Example:
 * <blockquote><pre>
 *     Input: 5
 *     Output:
 *     [
 *          [1],
 *         [1,1],
 *        [1,2,1],
 *       [1,3,3,1],
 *      [1,4,6,4,1]
 *     ]
 * </blockquote></pre>
 */
public class PascalsTriangle {
    public static class Solution1 {
        public List<List<Integer>> generate(int numRows) {
            if (numRows < 0)
                throw new IllegalArgumentException();
            List<List<Integer>> result = new ArrayList<>(numRows);
            if (numRows == 0)
                return result;
            List<Integer> pre = new ArrayList<>(1);
            pre.add(1);
            result.add(pre);
            List<Integer> cur;
            for (int i = 1; i < numRows; ++i) {
                cur = new ArrayList<>(i + 1);
                cur.add(1);
                for (int j = 1; j < i; ++j)
                    cur.add(pre.get(j - 1) + pre.get(j));
                cur.add(1);
                result.add(cur);
                pre = cur;
            }
            return result;
        }
    }
}

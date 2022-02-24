package io.binac.leetcode;

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

/**
 * <p>Given an integer <code>numRows</code>, return the first numRows of <strong>Pascal's triangle</strong>.</p>
 *
 * <p>In <strong>Pascal's triangle</strong>, each number is the sum of the two numbers directly above it as shown:</p>
 * <img alt="" src="https://upload.wikimedia.org/wikipedia/commons/0/0d/PascalTriangleAnimated2.gif" style="height:240px; width:260px">
 * <p>&nbsp;</p>
 * <p><strong>Example 1:</strong></p>
 * <pre><strong>Input:</strong> numRows = 5
 * <strong>Output:</strong> [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]
 * </pre><p><strong>Example 2:</strong></p>
 * <pre><strong>Input:</strong> numRows = 1
 * <strong>Output:</strong> [[1]]
 * </pre>
 * <p>&nbsp;</p>
 * <p><strong>Constraints:</strong></p>
 *
 * <ul>
 * 	<li><code>1 &lt;= numRows &lt;= 30</code></li>
 * </ul>
 */
public class PascalsTriangle {
    public static class Solution1 {
        public List<List<Integer>> generate(int numRows) {
            List<List<Integer>> result = new ArrayList<>(numRows);
            result.add(Collections.singletonList(1));
            List<Integer> pre, cur;
            for (int i = 1; i < numRows; ++i) {
                pre = result.get(i - 1);
                cur = new ArrayList<>(i + 1);
                cur.add(1);
                for (int j = 1; j < i; ++j)
                    cur.add(pre.get(j - 1) + pre.get(j));
                cur.add(1);
                result.add(cur);
            }
            return result;
        }
    }
}

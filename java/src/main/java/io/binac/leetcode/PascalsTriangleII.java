package io.binac.leetcode;

import java.util.ArrayList;
import java.util.List;

/**
 * <p>Given an integer <code>rowIndex</code>, return the <code>rowIndex<sup>th</sup></code> (<strong>0-indexed</strong>) row of the <strong>Pascal's triangle</strong>.</p>
 *
 * <p>In <strong>Pascal's triangle</strong>, each number is the sum of the two numbers directly above it as shown:</p>
 * <img alt="" src="https://upload.wikimedia.org/wikipedia/commons/0/0d/PascalTriangleAnimated2.gif" style="height:240px; width:260px">
 * <p>&nbsp;</p>
 * <p><strong>Example 1:</strong></p>
 * <pre><strong>Input:</strong> rowIndex = 3
 * <strong>Output:</strong> [1,3,3,1]
 * </pre><p><strong>Example 2:</strong></p>
 * <pre><strong>Input:</strong> rowIndex = 0
 * <strong>Output:</strong> [1]
 * </pre><p><strong>Example 3:</strong></p>
 * <pre><strong>Input:</strong> rowIndex = 1
 * <strong>Output:</strong> [1,1]
 * </pre>
 * <p>&nbsp;</p>
 * <p><strong>Constraints:</strong></p>
 *
 * <ul>
 * 	<li><code>0 &lt;= rowIndex &lt;= 33</code></li>
 * </ul>
 *
 * <p>&nbsp;</p>
 * <p><strong>Follow up:</strong> Could you optimize your algorithm to use only <code>O(rowIndex)</code> extra space?</p>
 */
public class PascalsTriangleII {
    public static class Solution1 {
        public List<Integer> getRow(int rowIndex) {
            List<Integer> result = new ArrayList<>(rowIndex + 1);
            for (int i = 0; i <= rowIndex; ++i) {
                result.add(1);
                for (int j = i - 1; j > 0; --j)
                    result.set(j, result.get(j) + result.get(j - 1));
            }
            return result;
        }
    }
}

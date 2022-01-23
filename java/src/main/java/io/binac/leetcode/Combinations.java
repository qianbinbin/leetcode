package io.binac.leetcode;

import java.util.ArrayList;
import java.util.List;

/**
 * <p>Given two integers <code>n</code> and <code>k</code>, return <em>all possible combinations of</em> <code>k</code> <em>numbers out of the range</em> <code>[1, n]</code>.</p>
 *
 * <p>You may return the answer in <strong>any order</strong>.</p>
 *
 * <p>&nbsp;</p>
 * <p><strong>Example 1:</strong></p>
 *
 * <pre><strong>Input:</strong> n = 4, k = 2
 * <strong>Output:</strong>
 * [
 *   [2,4],
 *   [3,4],
 *   [2,3],
 *   [1,2],
 *   [1,3],
 *   [1,4],
 * ]
 * </pre>
 *
 * <p><strong>Example 2:</strong></p>
 *
 * <pre><strong>Input:</strong> n = 1, k = 1
 * <strong>Output:</strong> [[1]]
 * </pre>
 *
 * <p>&nbsp;</p>
 * <p><strong>Constraints:</strong></p>
 *
 * <ul>
 * 	<li><code>1 &lt;= n &lt;= 20</code></li>
 * 	<li><code>1 &lt;= k &lt;= n</code></li>
 * </ul>
 */
public class Combinations {
    public static class Solution1 {
        private void combine(int n, int k, int i, List<Integer> path, List<List<Integer>> result) {
            if (path.size() == k) {
                result.add(new ArrayList<>(path));
                return;
            }
            for (int e = n - k + path.size() + 1; i <= e; ++i) {
                path.add(i);
                combine(n, k, i + 1, path, result);
                path.remove(path.size() - 1);
            }
        }

        public List<List<Integer>> combine(int n, int k) {
            List<List<Integer>> result = new ArrayList<>();
            combine(n, k, 1, new ArrayList<>(), result);
            return result;
        }
    }
}

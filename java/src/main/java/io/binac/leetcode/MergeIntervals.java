package io.binac.leetcode;


import java.util.Arrays;
import java.util.Comparator;

/**
 * <p>Given an array&nbsp;of <code>intervals</code>&nbsp;where <code>intervals[i] = [start<sub>i</sub>, end<sub>i</sub>]</code>, merge all overlapping intervals, and return <em>an array of the non-overlapping intervals that cover all the intervals in the input</em>.</p>
 *
 * <p>&nbsp;</p>
 * <p><strong>Example 1:</strong></p>
 *
 * <pre><strong>Input:</strong> intervals = [[1,3],[2,6],[8,10],[15,18]]
 * <strong>Output:</strong> [[1,6],[8,10],[15,18]]
 * <strong>Explanation:</strong> Since intervals [1,3] and [2,6] overlaps, merge them into [1,6].
 * </pre>
 *
 * <p><strong>Example 2:</strong></p>
 *
 * <pre><strong>Input:</strong> intervals = [[1,4],[4,5]]
 * <strong>Output:</strong> [[1,5]]
 * <strong>Explanation:</strong> Intervals [1,4] and [4,5] are considered overlapping.
 * </pre>
 *
 * <p>&nbsp;</p>
 * <p><strong>Constraints:</strong></p>
 *
 * <ul>
 * 	<li><code>1 &lt;= intervals.length &lt;= 10<sup>4</sup></code></li>
 * 	<li><code>intervals[i].length == 2</code></li>
 * 	<li><code>0 &lt;= start<sub>i</sub> &lt;= end<sub>i</sub> &lt;= 10<sup>4</sup></code></li>
 * </ul>
 */
public class MergeIntervals {
    public static class Solution1 {
        public int[][] merge(int[][] intervals) {
            int[][] result = new int[intervals.length][];
            if (intervals.length == 0)
                return result;
            Arrays.sort(intervals, Comparator.comparingInt(o -> o[0]));
            int[] last;
            last = result[0] = Arrays.copyOf(intervals[0], 2);
            int j = 1;
            for (int i = 1; i < intervals.length; ++i) {
                if (last[1] >= intervals[i][0]) {
                    last[1] = Integer.max(last[1], intervals[i][1]);
                } else {
                    last = result[j++] = Arrays.copyOf(intervals[i], 2);
                }
            }
            result = Arrays.copyOf(result, j);
            return result;
        }
    }
}

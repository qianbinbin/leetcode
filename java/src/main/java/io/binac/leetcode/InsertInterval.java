package io.binac.leetcode;

import java.util.Arrays;

/**
 * <p>Given a set of <em>non-overlapping</em> intervals, insert a new interval into the intervals (merge if necessary).</p>
 *
 * <p>You may assume that the intervals were initially sorted according to their start times.</p>
 *
 * <p>&nbsp;</p>
 * <p><strong>Example 1:</strong></p>
 *
 * <pre><strong>Input:</strong> intervals = [[1,3],[6,9]], newInterval = [2,5]
 * <strong>Output:</strong> [[1,5],[6,9]]
 * </pre>
 *
 * <p><strong>Example 2:</strong></p>
 *
 * <pre><strong>Input:</strong> intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], newInterval = [4,8]
 * <strong>Output:</strong> [[1,2],[3,10],[12,16]]
 * <strong>Explanation:</strong> Because the new interval <code>[4,8]</code> overlaps with <code>[3,5],[6,7],[8,10]</code>.</pre>
 *
 * <p><strong>Example 3:</strong></p>
 *
 * <pre><strong>Input:</strong> intervals = [], newInterval = [5,7]
 * <strong>Output:</strong> [[5,7]]
 * </pre>
 *
 * <p><strong>Example 4:</strong></p>
 *
 * <pre><strong>Input:</strong> intervals = [[1,5]], newInterval = [2,3]
 * <strong>Output:</strong> [[1,5]]
 * </pre>
 *
 * <p><strong>Example 5:</strong></p>
 *
 * <pre><strong>Input:</strong> intervals = [[1,5]], newInterval = [2,7]
 * <strong>Output:</strong> [[1,7]]
 * </pre>
 *
 * <p>&nbsp;</p>
 * <p><strong>Constraints:</strong></p>
 *
 * <ul>
 * 	<li><code>0 &lt;= intervals.length &lt;= 10<sup>4</sup></code></li>
 * 	<li><code>intervals[i].length == 2</code></li>
 * 	<li><code>0 &lt;=&nbsp;intervals[i][0] &lt;=&nbsp;intervals[i][1] &lt;= 10<sup>5</sup></code></li>
 * 	<li><code>intervals</code>&nbsp;is sorted by <code>intervals[i][0]</code> in <strong>ascending</strong>&nbsp;order.</li>
 * 	<li><code>newInterval.length == 2</code></li>
 * 	<li><code>0 &lt;=&nbsp;newInterval[0] &lt;=&nbsp;newInterval[1] &lt;= 10<sup>5</sup></code></li>
 * </ul>
 */
public class InsertInterval {
    public static class Solution1 {
        public int[][] insert(int[][] intervals, int[] newInterval) {
            int[][] result = new int[intervals.length + 1][];
            int size = 0;
            int i = 0;
            for (; i < intervals.length && intervals[i][1] < newInterval[0]; ++i)
                result[size++] = Arrays.copyOf(intervals[i], 2);
            int[] merge = Arrays.copyOf(newInterval, 2);
            for (; i < intervals.length && intervals[i][0] <= newInterval[1]; ++i) {
                merge[0] = Integer.min(merge[0], intervals[i][0]);
                merge[1] = Integer.max(merge[1], intervals[i][1]);
            }
            result[size++] = merge;
            for (; i < intervals.length; ++i)
                result[size++] = Arrays.copyOf(intervals[i], 2);
            result = Arrays.copyOf(result, size);
            return result;
        }
    }
}

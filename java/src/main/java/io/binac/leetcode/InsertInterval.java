package io.binac.leetcode;

import io.binac.leetcode.util.Interval;

import java.util.ArrayList;
import java.util.List;

/**
 * Given a set of non-overlapping intervals, insert a new interval into the intervals (merge if necessary).
 * <p>
 * <p>You may assume that the intervals were initially sorted according to their start times.
 * <p>
 * <p>Example 1:
 * <blockquote><pre>
 *     Input: intervals = [[1,3],[6,9]], newInterval = [2,5]
 *     Output: [[1,5],[6,9]]
 * </blockquote></pre>
 * Example 2:
 * <blockquote><pre>
 *     Input: intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], newInterval = [4,8]
 *     Output: [[1,2],[3,10],[12,16]]
 *     Explanation: Because the new interval [4,8] overlaps with [3,5],[6,7],[8,10].
 * </blockquote></pre>
 */
public class InsertInterval {
    public static class Solution1 {
        public List<Interval> insert(List<Interval> intervals, Interval newInterval) {
            final int size = intervals.size();
            List<Interval> result = new ArrayList<>();
            int i = 0;
            for (; i < size; ++i) {
                Interval interval = intervals.get(i);
                if (interval.end >= newInterval.start) break;
                result.add(new Interval(interval.start, interval.end));
            }
            Interval merge = new Interval(newInterval.start, newInterval.end);
            for (; i < size; ++i) {
                Interval interval = intervals.get(i);
                if (interval.start > newInterval.end) break;
                merge.start = Math.min(merge.start, interval.start);
                merge.end = Math.max(merge.end, interval.end);
            }
            result.add(merge);
            for (; i < size; ++i) {
                Interval interval = intervals.get(i);
                result.add(new Interval(interval.start, interval.end));
            }
            return result;
        }
    }
}

package io.binac.leetcode;

import io.binac.leetcode.util.Interval;

import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.List;

/**
 * Given a collection of intervals, merge all overlapping intervals.
 * <p>
 * <p>Example 1:
 * <blockquote><pre>
 *     Input: [[1,3],[2,6],[8,10],[15,18]]
 *     Output: [[1,6],[8,10],[15,18]]
 *     Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into [1,6].
 * </blockquote></pre>
 * Example 2:
 * <blockquote><pre>
 *     Input: [[1,4],[4,5]]
 *     Output: [[1,5]]
 *     Explanation: Intervals [1,4] and [4,5] are considerred overlapping.
 * </blockquote></pre>
 */
public class MergeIntervals {
    public static class Solution1 {
        private Interval copyOf(Interval interval) {
            return new Interval(interval.start, interval.end);
        }

        public List<Interval> merge(List<Interval> intervals) {
            if (intervals.isEmpty())
                return Collections.emptyList();

            intervals.sort(Comparator.comparingInt(a -> a.start));

            List<Interval> result = new ArrayList<>();
            Interval last = copyOf(intervals.get(0));
            result.add(last);
            final int size = intervals.size();
            for (int i = 1; i < size; ++i) {
                Interval interval = intervals.get(i);
                if (last.end >= interval.start) {
                    last.end = Math.max(last.end, interval.end);
                } else {
                    last = copyOf(interval);
                    result.add(last);
                }
            }
            return result;
        }
    }
}

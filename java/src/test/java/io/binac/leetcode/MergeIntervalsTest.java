package io.binac.leetcode;

import io.binac.leetcode.util.Interval;
import org.junit.jupiter.api.Test;

import java.util.Arrays;
import java.util.Collections;
import java.util.List;

import static org.junit.jupiter.api.Assertions.*;

class MergeIntervalsTest {
    private final MergeIntervals.Solution1 solution1 = new MergeIntervals.Solution1();

    @Test
    void test1() {
        List<Interval> intervals1 = Arrays.asList(
                new Interval(1, 3),
                new Interval(2, 6),
                new Interval(8, 10),
                new Interval(15, 18)
        );
        List<Interval> expected1 = Arrays.asList(
                new Interval(1, 6),
                new Interval(8, 10),
                new Interval(15, 18)
        );
        assertEquals(expected1, solution1.merge(intervals1));

        List<Interval> intervals2 = Arrays.asList(
                new Interval(1, 4),
                new Interval(4, 5)
        );
        List<Interval> expected2 = Collections.singletonList(
                new Interval(1, 5)
        );
        assertEquals(expected2, solution1.merge(intervals2));
    }
}
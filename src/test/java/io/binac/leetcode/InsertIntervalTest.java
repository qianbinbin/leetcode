package io.binac.leetcode;

import io.binac.leetcode.util.Interval;
import org.junit.jupiter.api.Test;

import java.util.Arrays;
import java.util.List;

import static org.junit.jupiter.api.Assertions.*;

class InsertIntervalTest {
    private final InsertInterval.Solution1 solution1 = new InsertInterval.Solution1();

    @Test
    void test1() {
        List<Interval> intervals1 = Arrays.asList(
                new Interval(1, 3),
                new Interval(6, 9)
        );
        List<Interval> result1 = solution1.insert(intervals1, new Interval(2, 5));
        List<Interval> expected1 = Arrays.asList(
                new Interval(1, 5),
                new Interval(6, 9)
        );
        assertEquals(expected1, result1);

        List<Interval> intervals2 = Arrays.asList(
                new Interval(1, 2),
                new Interval(3, 5),
                new Interval(6, 7),
                new Interval(8, 10),
                new Interval(12, 16)
        );
        List<Interval> result2 = solution1.insert(intervals2, new Interval(4, 8));
        List<Interval> expected2 = Arrays.asList(
                new Interval(1, 2),
                new Interval(3, 10),
                new Interval(12, 16)
        );
        assertEquals(expected2, result2);
    }
}
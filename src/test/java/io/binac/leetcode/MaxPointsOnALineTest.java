package io.binac.leetcode;

import io.binac.leetcode.util.Point;
import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class MaxPointsOnALineTest {

    private final MaxPointsOnALine.Solution1 solution1 = new MaxPointsOnALine.Solution1();

    private final Point points1[] = {new Point(0, 0), new Point(1, 1), new Point(0, 0)};

    private final int expected1 = 3;

    private final Point points2[] = {new Point(1, 1), new Point(3, 2), new Point(5, 3),
            new Point(4, 1), new Point(2, 3), new Point(1, 4)};

    private final int expected2 = 4;

    @Test
    void test1() {
        assertEquals(expected1, solution1.maxPoints(points1));
        assertEquals(expected2, solution1.maxPoints(points2));
    }
}
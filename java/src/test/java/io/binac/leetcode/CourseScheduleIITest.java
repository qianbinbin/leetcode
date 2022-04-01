package io.binac.leetcode;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class CourseScheduleIITest {
    private static final CourseScheduleII.Solution1 SOLUTION1 = new CourseScheduleII.Solution1();
    private static final CourseScheduleII.Solution2 SOLUTION2 = new CourseScheduleII.Solution2();

    private final int NUMCOURSES1 = 2;
    private final int[][] PREREQUISITES1 = {{1, 0}};
    private final int[] EXPECTED1 = {0, 1};

    private final int NUMCOURSES2 = 4;
    private final int[][] PREREQUISITES2 = {{1, 0}, {2, 0}, {3, 1}, {3, 2}};
    private final int[] EXPECTED21 = {0, 1, 2, 3};
    private final int[] EXPECTED22 = {0, 2, 1, 3};

    private final int NUMCOURSES3 = 1;
    private final int[][] PREREQUISITES3 = {};
    private final int[] EXPECTED3 = {0};

    @Test
    void test1() {
        assertArrayEquals(EXPECTED1, SOLUTION1.findOrder(NUMCOURSES1, PREREQUISITES1));
        assertArrayEquals(EXPECTED21, SOLUTION1.findOrder(NUMCOURSES2, PREREQUISITES2));
        assertArrayEquals(EXPECTED3, SOLUTION1.findOrder(NUMCOURSES3, PREREQUISITES3));
    }

    @Test
    void test2() {
        assertArrayEquals(EXPECTED1, SOLUTION2.findOrder(NUMCOURSES1, PREREQUISITES1));
        assertArrayEquals(EXPECTED22, SOLUTION2.findOrder(NUMCOURSES2, PREREQUISITES2));
        assertArrayEquals(EXPECTED3, SOLUTION2.findOrder(NUMCOURSES3, PREREQUISITES3));
    }
}
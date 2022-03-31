package io.binac.leetcode;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class CourseScheduleTest {
    private static final CourseSchedule.Solution1 SOLUTION1 = new CourseSchedule.Solution1();
    private static final CourseSchedule.Solution2 SOLUTION2 = new CourseSchedule.Solution2();

    private final int NUMCOURSES1 = 2;
    private final int[][] PREREQUISITES1 = {{1, 0}};
    private final boolean EXPECTED1 = true;

    private final int NUMCOURSES2 = 2;
    private final int[][] PREREQUISITES2 = {{1, 0}, {0, 1}};
    private final boolean EXPECTED2 = false;

    @Test
    void test1() {
        assertEquals(EXPECTED1, SOLUTION1.canFinish(NUMCOURSES1, PREREQUISITES1));
        assertEquals(EXPECTED2, SOLUTION1.canFinish(NUMCOURSES2, PREREQUISITES2));
    }

    @Test
    void test2() {
        assertEquals(EXPECTED1, SOLUTION2.canFinish(NUMCOURSES1, PREREQUISITES1));
        assertEquals(EXPECTED2, SOLUTION2.canFinish(NUMCOURSES2, PREREQUISITES2));
    }
}
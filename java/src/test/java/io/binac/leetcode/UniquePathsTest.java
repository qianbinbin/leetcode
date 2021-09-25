package io.binac.leetcode;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class UniquePathsTest {
    private static final UniquePaths.Solution1 SOLUTION1 = new UniquePaths.Solution1();
    private static final UniquePaths.Solution2 SOLUTION2 = new UniquePaths.Solution2();

    @Test
    void test1() {
        assertEquals(28, SOLUTION1.uniquePaths(3, 7));
        assertEquals(3, SOLUTION1.uniquePaths(3, 2));
        assertEquals(28, SOLUTION1.uniquePaths(7, 3));
        assertEquals(6, SOLUTION1.uniquePaths(3, 3));
    }

    @Test
    void test2() {
        assertEquals(28, SOLUTION2.uniquePaths(3, 7));
        assertEquals(3, SOLUTION2.uniquePaths(3, 2));
        assertEquals(28, SOLUTION2.uniquePaths(7, 3));
        assertEquals(6, SOLUTION2.uniquePaths(3, 3));
    }
}
package io.binac.leetcode;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class UniquePathsTest {
    private final UniquePaths.Solution1 solution1 = new UniquePaths.Solution1();

    private final UniquePaths.Solution2 solution2 = new UniquePaths.Solution2();

    @Test
    void test1() {
        assertEquals(3, solution1.uniquePaths(3, 2));
        assertEquals(28, solution1.uniquePaths(7, 3));
    }

    @Test
    void test2() {
        assertEquals(3, solution2.uniquePaths(3, 2));
        assertEquals(28, solution2.uniquePaths(7, 3));
    }
}
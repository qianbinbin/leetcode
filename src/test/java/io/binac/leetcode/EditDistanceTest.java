package io.binac.leetcode;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class EditDistanceTest {
    private final EditDistance.Solution1 solution1 = new EditDistance.Solution1();

    @Test
    void test1() {
        assertEquals(3, solution1.minDistance("horse", "ros"));
        assertEquals(5, solution1.minDistance("intention", "execution"));
    }
}
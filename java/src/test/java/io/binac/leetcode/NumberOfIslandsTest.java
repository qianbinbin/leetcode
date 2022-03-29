package io.binac.leetcode;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class NumberOfIslandsTest {
    private static final NumberOfIslands.Solution1 SOLUTION1 = new NumberOfIslands.Solution1();

    private char[][] getGRID1() {
        return new char[][]{
                {'1', '1', '1', '1', '0'},
                {'1', '1', '0', '1', '0'},
                {'1', '1', '0', '0', '0'},
                {'0', '0', '0', '0', '0'}
        };
    }

    private final int EXPECTED1 = 1;

    private char[][] getGRID2() {
        return new char[][]{
                {'1', '1', '0', '0', '0'},
                {'1', '1', '0', '0', '0'},
                {'0', '0', '1', '0', '0'},
                {'0', '0', '0', '1', '1'}
        };
    }

    private final int EXPECTED2 = 3;

    @Test
    void test1() {
        assertEquals(EXPECTED1, SOLUTION1.numIslands(getGRID1()));
        assertEquals(EXPECTED2, SOLUTION1.numIslands(getGRID2()));
    }
}
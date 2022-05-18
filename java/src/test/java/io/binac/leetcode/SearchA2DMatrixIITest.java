package io.binac.leetcode;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class SearchA2DMatrixIITest {
    private static final SearchA2DMatrixII.Solution1 SOLUTION1 = new SearchA2DMatrixII.Solution1();

    private final int[][] MATRIX1 = {{1, 4, 7, 11, 15}, {2, 5, 8, 12, 19}, {3, 6, 9, 16, 22}, {10, 13, 14, 17, 24}, {18, 21, 23, 26, 30}};
    private final int TARGET1 = 5;
    private final boolean EXPECTED1 = true;

    private final int[][] MATRIX2 = {{1, 4, 7, 11, 15}, {2, 5, 8, 12, 19}, {3, 6, 9, 16, 22}, {10, 13, 14, 17, 24}, {18, 21, 23, 26, 30}};
    private final int TARGET2 = 20;
    private final boolean EXPECTED2 = false;

    @Test
    void test1() {
        assertEquals(EXPECTED1, SOLUTION1.searchMatrix(MATRIX1, TARGET1));
        assertEquals(EXPECTED2, SOLUTION1.searchMatrix(MATRIX2, TARGET2));
    }
}
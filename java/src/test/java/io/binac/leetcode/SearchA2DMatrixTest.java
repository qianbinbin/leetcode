package io.binac.leetcode;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class SearchA2DMatrixTest {
    private static final SearchA2DMatrix.Solution1 SOLUTION1 = new SearchA2DMatrix.Solution1();

    private final int[][] MATRIX1 = {
            {1, 3, 5, 7},
            {10, 11, 16, 20},
            {23, 30, 34, 50}
    };
    private final int TARGET1 = 3;
    private final boolean EXPECTED1 = true;

    private final int[][] MATRIX2 = {
            {1, 3, 5, 7},
            {10, 11, 16, 20},
            {23, 30, 34, 50}
    };
    private final int TARGET2 = 13;
    private final boolean EXPECTED2 = false;

    @Test
    void test1() {
        assertEquals(EXPECTED1, SOLUTION1.searchMatrix(MATRIX1, TARGET1));
        assertEquals(EXPECTED2, SOLUTION1.searchMatrix(MATRIX2, TARGET2));
    }
}
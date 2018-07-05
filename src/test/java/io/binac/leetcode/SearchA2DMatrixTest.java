package io.binac.leetcode;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class SearchA2DMatrixTest {
    private final SearchA2DMatrix.Solution1 solution1 = new SearchA2DMatrix.Solution1();

    @Test
    void test1() {
        int matrix[][] = {
                {1, 3, 5, 7},
                {10, 11, 16, 20},
                {23, 30, 34, 50}
        };
        assertTrue(solution1.searchMatrix(matrix, 3));
        assertFalse(solution1.searchMatrix(matrix, 13));
    }
}
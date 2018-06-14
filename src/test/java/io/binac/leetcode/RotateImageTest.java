package io.binac.leetcode;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class RotateImageTest {
    private final RotateImage.Solution1 solution1 = new RotateImage.Solution1();

    @Test
    void test1() {
        int matrix1[][] = {
                {1, 2, 3},
                {4, 5, 6},
                {7, 8, 9}
        };
        int expected1[][] = {
                {7, 4, 1},
                {8, 5, 2},
                {9, 6, 3}
        };
        solution1.rotate(matrix1);
        assertArrayEquals(expected1, matrix1);

        int matrix2[][] = {
                {5, 1, 9, 11},
                {2, 4, 8, 10},
                {13, 3, 6, 7},
                {15, 14, 12, 16}
        };
        int expected2[][] = {
                {15, 13, 2, 5},
                {14, 3, 4, 1},
                {12, 6, 8, 9},
                {16, 7, 10, 11}
        };
        solution1.rotate(matrix2);
        assertArrayEquals(expected2, matrix2);
    }
}
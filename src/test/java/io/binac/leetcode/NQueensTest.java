package io.binac.leetcode;

import org.junit.jupiter.api.Test;

import java.util.Arrays;
import java.util.List;

import static org.junit.jupiter.api.Assertions.*;

class NQueensTest {
    private final NQueens.Solution1 solution1 = new NQueens.Solution1();

    @Test
    void test1() {
        List<List<String>> result = solution1.solveNQueens(4);
        List<List<String>> expected = Arrays.asList(
                Arrays.asList(
                        ".Q..",
                        "...Q",
                        "Q...",
                        "..Q."
                ),
                Arrays.asList(
                        "..Q.",
                        "Q...",
                        "...Q",
                        ".Q.."
                )
        );
        assertEquals(expected, result);
    }
}
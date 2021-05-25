package io.binac.leetcode;

import org.junit.jupiter.api.Test;

import java.util.Arrays;
import java.util.Collections;
import java.util.List;

import static org.junit.jupiter.api.Assertions.*;

class NQueensTest {
    private static final NQueens.Solution1 SOLUTION1 = new NQueens.Solution1();

    private final int N1 = 4;
    private final List<List<String>> EXPECTED1 = Arrays.asList(
            Arrays.asList(".Q..", "...Q", "Q...", "..Q."),
            Arrays.asList("..Q.", "Q...", "...Q", ".Q..")
    );

    private final int N2 = 1;
    private final List<List<String>> EXPECTED2 = Collections.singletonList(
            Collections.singletonList("Q")
    );

    @Test
    void test1() {
        assertEquals(EXPECTED1, SOLUTION1.solveNQueens(N1));
        assertEquals(EXPECTED2, SOLUTION1.solveNQueens(N2));
    }
}
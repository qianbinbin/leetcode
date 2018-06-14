package io.binac.leetcode;

import org.junit.jupiter.api.Test;

import java.util.Arrays;
import java.util.List;

import static org.junit.jupiter.api.Assertions.*;

class PermutationsIITest {
    private final PermutationsII.Solution1 solution1 = new PermutationsII.Solution1();

    @Test
    void test1() {
        int nums[] = {1, 1, 2};
        List<List<Integer>> expected = Arrays.asList(
                Arrays.asList(1, 1, 2),
                Arrays.asList(1, 2, 1),
                Arrays.asList(2, 1, 1)
        );
        assertEquals(expected, solution1.permuteUnique(nums));
    }
}
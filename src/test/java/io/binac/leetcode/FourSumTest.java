package io.binac.leetcode;

import org.junit.jupiter.api.Test;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

import static org.junit.jupiter.api.Assertions.*;

class FourSumTest {
    private final FourSum.Solution1 solution1 = new FourSum.Solution1();

    @Test
    void test1() {
        int nums[] = {1, 0, -1, 0, -2, 2};
        List<List<Integer>> expected = new ArrayList<>();
        expected.add(Arrays.asList(-2, -1, 1, 2));
        expected.add(Arrays.asList(-2, 0, 0, 2));
        expected.add(Arrays.asList(-1, 0, 0, 1));
        assertEquals(expected, solution1.fourSum(nums, 0));
    }
}
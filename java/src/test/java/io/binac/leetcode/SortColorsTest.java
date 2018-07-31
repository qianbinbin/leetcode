package io.binac.leetcode;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class SortColorsTest {
    private final SortColors.Solution1 solution1 = new SortColors.Solution1();

    private final SortColors.Solution2 solution2 = new SortColors.Solution2();

    @Test
    void test1() {
        int nums[] = {2, 0, 2, 1, 1, 0};
        solution1.sortColors(nums);
        int expected[] = {0, 0, 1, 1, 2, 2};
        assertArrayEquals(expected, nums);
    }

    @Test
    void test2() {
        int nums[] = {2, 0, 2, 1, 1, 0};
        solution2.sortColors(nums);
        int expected[] = {0, 0, 1, 1, 2, 2};
        assertArrayEquals(expected, nums);
    }
}
package io.binac.leetcode;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class FindFirstAndLastPositionOfElementInSortedArrayTest {
    private final FindFirstAndLastPositionOfElementInSortedArray.Solution1 solution1 = new FindFirstAndLastPositionOfElementInSortedArray.Solution1();

    @Test
    void test1() {
        int nums[] = {5, 7, 7, 8, 8, 10};
        int result1[] = solution1.searchRange(nums, 8);
        int expected1[] = {3, 4};
        assertArrayEquals(expected1, result1);

        int result2[] = solution1.searchRange(nums, 6);
        int expected2[] = {-1, -1};
        assertArrayEquals(expected2, result2);
    }
}
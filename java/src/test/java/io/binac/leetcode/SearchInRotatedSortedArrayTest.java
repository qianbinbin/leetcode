package io.binac.leetcode;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class SearchInRotatedSortedArrayTest {
    private final SearchInRotatedSortedArray.Solution1 solution1 = new SearchInRotatedSortedArray.Solution1();

    @Test
    void test1() {
        int nums[] = {4, 5, 6, 7, 0, 1, 2};
        assertEquals(4, solution1.search(nums, 0));
        assertEquals(-1, solution1.search(nums, 3));
    }
}
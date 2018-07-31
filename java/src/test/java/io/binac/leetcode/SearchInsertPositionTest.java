package io.binac.leetcode;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class SearchInsertPositionTest {
    private final SearchInsertPosition.Solution1 solution1 = new SearchInsertPosition.Solution1();

    @Test
    void test1() {
        int nums[] = {1, 3, 5, 6};
        assertEquals(2, solution1.searchInsert(nums, 5));
        assertEquals(1, solution1.searchInsert(nums, 2));
        assertEquals(4, solution1.searchInsert(nums, 7));
        assertEquals(0, solution1.searchInsert(nums, 0));
    }
}
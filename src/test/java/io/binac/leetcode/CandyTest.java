package io.binac.leetcode;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class CandyTest {
    private final Candy.Solution1 solution1 = new Candy.Solution1();

    @Test
    void test1() {
        int ratings1[] = {1, 0, 2};
        assertEquals(5, solution1.candy(ratings1));

        int ratings2[] = {1, 2, 2};
        assertEquals(4, solution1.candy(ratings2));
    }
}
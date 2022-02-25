package io.binac.leetcode;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class BestTimeToBuyAndSellStockIITest {
    private static final BestTimeToBuyAndSellStockII.Solution1 SOLUTION1 = new BestTimeToBuyAndSellStockII.Solution1();

    private final int[] PRICES1 = {7, 1, 5, 3, 6, 4};
    private final int EXPECTED1 = 7;

    private final int[] PRICES2 = {1, 2, 3, 4, 5};
    private final int EXPECTED2 = 4;

    private final int[] PRICES3 = {7, 6, 4, 3, 1};
    private final int EXPECTED3 = 0;

    @Test
    void test1() {
        assertEquals(EXPECTED1, SOLUTION1.maxProfit(PRICES1));
        assertEquals(EXPECTED2, SOLUTION1.maxProfit(PRICES2));
        assertEquals(EXPECTED3, SOLUTION1.maxProfit(PRICES3));
    }
}
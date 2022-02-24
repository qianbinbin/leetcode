package io.binac.leetcode;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class BestTimeToBuyAndSellStockTest {
    private static final BestTimeToBuyAndSellStock.Solution1 SOLUTION1 = new BestTimeToBuyAndSellStock.Solution1();

    private final int[] PRICES1 = {7, 1, 5, 3, 6, 4};
    private final int EXPECTED1 = 5;

    private final int[] PRICES2 = {7, 6, 4, 3, 1};
    private final int EXPECTED2 = 0;

    @Test
    void test1() {
        assertEquals(EXPECTED1, SOLUTION1.maxProfit(PRICES1));
        assertEquals(EXPECTED2, SOLUTION1.maxProfit(PRICES2));
    }
}
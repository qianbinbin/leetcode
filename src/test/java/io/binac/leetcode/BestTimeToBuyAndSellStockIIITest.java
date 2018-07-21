package io.binac.leetcode;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class BestTimeToBuyAndSellStockIIITest {
    private final BestTimeToBuyAndSellStockIII.Solution1 solution1 = new BestTimeToBuyAndSellStockIII.Solution1();

    @Test
    void test1() {
        int prices1[] = {3, 3, 5, 0, 0, 3, 1, 4};
        assertEquals(6, solution1.maxProfit(prices1));

        int prices2[] = {1, 2, 3, 4, 5};
        assertEquals(4, solution1.maxProfit(prices2));

        int prices3[] = {7, 6, 4, 3, 1};
        assertEquals(0, solution1.maxProfit(prices3));
    }
}
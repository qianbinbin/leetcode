package io.binac.leetcode;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class BestTimeToBuyAndSellStockTest {
    private final BestTimeToBuyAndSellStock.Solution1 solution1 = new BestTimeToBuyAndSellStock.Solution1();

    @Test
    void test1() {
        int prices1[] = {7, 1, 5, 3, 6, 4};
        assertEquals(5, solution1.maxProfit(prices1));

        int prices2[] = {7, 6, 4, 3, 1};
        assertEquals(0, solution1.maxProfit(prices2));
    }
}
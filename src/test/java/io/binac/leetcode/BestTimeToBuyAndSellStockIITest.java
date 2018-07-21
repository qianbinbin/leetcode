package io.binac.leetcode;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class BestTimeToBuyAndSellStockIITest {
    private final BestTimeToBuyAndSellStockII.Solution1 solution1 = new BestTimeToBuyAndSellStockII.Solution1();

    private final BestTimeToBuyAndSellStockII.Solution2 solution2 = new BestTimeToBuyAndSellStockII.Solution2();

    @Test
    void test1() {
        int prices1[] = {7, 1, 5, 3, 6, 4};
        assertEquals(7, solution1.maxProfit(prices1));

        int prices2[] = {1, 2, 3, 4, 5};
        assertEquals(4, solution1.maxProfit(prices2));

        int prices3[] = {7, 6, 4, 3, 1};
        assertEquals(0, solution1.maxProfit(prices3));
    }

    @Test
    void test2() {
        int prices1[] = {7, 1, 5, 3, 6, 4};
        assertEquals(7, solution2.maxProfit(prices1));

        int prices2[] = {1, 2, 3, 4, 5};
        assertEquals(4, solution2.maxProfit(prices2));

        int prices3[] = {7, 6, 4, 3, 1};
        assertEquals(0, solution2.maxProfit(prices3));
    }
}
package io.binac.leetcode;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class BestTimeToBuyAndSellStockIIITest {
    private static final BestTimeToBuyAndSellStockIII.Solution1 SOLUTION1 = new BestTimeToBuyAndSellStockIII.Solution1();
    private static final BestTimeToBuyAndSellStockIII.Solution2 SOLUTION2 = new BestTimeToBuyAndSellStockIII.Solution2();

    private final int[] PRICES1 = {3, 3, 5, 0, 0, 3, 1, 4};
    private final int EXPECTED1 = 6;

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

    @Test
    void test2() {
        assertEquals(EXPECTED1, SOLUTION2.maxProfit(PRICES1));
        assertEquals(EXPECTED2, SOLUTION2.maxProfit(PRICES2));
        assertEquals(EXPECTED3, SOLUTION2.maxProfit(PRICES3));
    }
}
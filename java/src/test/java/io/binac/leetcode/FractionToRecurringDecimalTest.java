package io.binac.leetcode;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class FractionToRecurringDecimalTest {
    private static final FractionToRecurringDecimal.Solution1 SOLUTION1 = new FractionToRecurringDecimal.Solution1();

    private final int NUMERATOR1 = 1, DENOMINATOR1 = 2;
    private final String EXPECTED1 = "0.5";

    private final int NUMERATOR2 = 2, DENOMINATOR2 = 1;
    private final String EXPECTED2 = "2";

    private final int NUMERATOR3 = 4, DENOMINATOR3 = 333;
    private final String EXPECTED3 = "0.(012)";

    @Test
    void test1() {
        assertEquals(EXPECTED1, SOLUTION1.fractionToDecimal(NUMERATOR1, DENOMINATOR1));
        assertEquals(EXPECTED2, SOLUTION1.fractionToDecimal(NUMERATOR2, DENOMINATOR2));
        assertEquals(EXPECTED3, SOLUTION1.fractionToDecimal(NUMERATOR3, DENOMINATOR3));
    }
}
package io.binac.leetcode;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class ExcelSheetColumnNumberTest {
    private static final ExcelSheetColumnNumber.Solution1 SOLUTION1 = new ExcelSheetColumnNumber.Solution1();

    private final String COLUMNTITLE1 = "A";
    private final int EXPECTED1 = 1;

    private final String COLUMNTITLE2 = "AB";
    private final int EXPECTED2 = 28;

    private final String COLUMNTITLE3 = "ZY";
    private final int EXPECTED3 = 701;

    @Test
    void test1() {
        assertEquals(EXPECTED1, SOLUTION1.titleToNumber(COLUMNTITLE1));
        assertEquals(EXPECTED2, SOLUTION1.titleToNumber(COLUMNTITLE2));
        assertEquals(EXPECTED3, SOLUTION1.titleToNumber(COLUMNTITLE3));
    }
}
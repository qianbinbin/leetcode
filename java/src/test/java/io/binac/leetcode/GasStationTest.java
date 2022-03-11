package io.binac.leetcode;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class GasStationTest {
    private static final GasStation.Solution1 SOLUTION1 = new GasStation.Solution1();

    private final int[] GAS1 = {1, 2, 3, 4, 5}, COST1 = {3, 4, 5, 1, 2};
    private final int EXPECTED1 = 3;

    private final int[] GAS2 = {2, 3, 4}, COST2 = {3, 4, 3};
    private final int EXPECTED2 = -1;

    @Test
    void test1() {
        assertEquals(EXPECTED1, SOLUTION1.canCompleteCircuit(GAS1, COST1));
        assertEquals(EXPECTED2, SOLUTION1.canCompleteCircuit(GAS2, COST2));
    }
}
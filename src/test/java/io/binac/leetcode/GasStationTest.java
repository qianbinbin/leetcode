package io.binac.leetcode;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class GasStationTest {
    private final GasStation.Solution1 solution1 = new GasStation.Solution1();

    @Test
    void test1() {
        int gas1[] = {1, 2, 3, 4, 5}, cost1[] = {3, 4, 5, 1, 2};
        assertEquals(3, solution1.canCompleteCircuit(gas1, cost1));

        int gas2[] = {2, 3, 4}, cost2[] = {3, 4, 3};
        assertEquals(-1, solution1.canCompleteCircuit(gas2, cost2));
    }
}
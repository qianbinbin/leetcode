package io.binac.leetcode;

/**
 * There are N gas stations along a circular route, where the amount of gas at station i is gas[i].
 * <p>
 * <p>You have a car with an unlimited gas tank and it costs cost[i] of gas to travel from station i to its next station (i+1). You begin the journey with an empty tank at one of the gas stations.
 * <p>
 * <p>Return the starting gas station's index if you can travel around the circuit once in the clockwise direction, otherwise return -1.
 * <p>
 * <p>Note:
 * <p>
 * <p>If there exists a solution, it is guaranteed to be unique.
 * <p>Both input arrays are non-empty and have the same length.
 * <p>Each element in the input arrays is a non-negative integer.
 * <p>
 * <p>Example 1:
 * <blockquote><pre>
 *     Input:
 *     gas  = [1,2,3,4,5]
 *     cost = [3,4,5,1,2]
 *
 *     Output: 3
 *
 *     Explanation:
 *     Start at station 3 (index 3) and fill up with 4 unit of gas. Your tank = 0 + 4 = 4
 *     Travel to station 4. Your tank = 4 - 1 + 5 = 8
 *     Travel to station 0. Your tank = 8 - 2 + 1 = 7
 *     Travel to station 1. Your tank = 7 - 3 + 2 = 6
 *     Travel to station 2. Your tank = 6 - 4 + 3 = 5
 *     Travel to station 3. The cost is 5. Your gas is just enough to travel back to station 3.
 *     Therefore, return 3 as the starting index.
 * </blockquote></pre>
 * Example 2:
 * <blockquote><pre>
 *     Input:
 *     gas  = [2,3,4]
 *     cost = [3,4,3]
 *
 *     Output: -1
 *
 *     Explanation:
 *     You can't start at station 0 or 1, as there is not enough gas to travel to the next station.
 *     Let's start at station 2 and fill up with 4 unit of gas. Your tank = 0 + 4 = 4
 *     Travel to station 0. Your tank = 4 - 3 + 2 = 3
 *     Travel to station 1. Your tank = 3 - 3 + 3 = 3
 *     You cannot travel back to station 2, as it requires 4 unit of gas but you only have 3.
 *     Therefore, you can't travel around the circuit once no matter where you start.
 * </blockquote></pre>
 */
public class GasStation {
    public static class Solution1 {
        public int canCompleteCircuit(int[] gas, int[] cost) {
            final int len = gas.length;
            int start = 0;
            int tank = 0, total = 0;
            for (int i = 0; i < len; ++i) {
                tank += gas[i] - cost[i];
                total += gas[i] - cost[i];
                if (tank < 0) {
                    start = i + 1;
                    tank = 0;
                }
            }
            return total < 0 ? -1 : start;
        }
    }
}

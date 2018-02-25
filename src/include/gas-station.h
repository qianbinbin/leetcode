#ifndef LEETCODE_GAS_STATION_H
#define LEETCODE_GAS_STATION_H

/**
 * There are N gas stations along a circular route, where the amount of gas at station i is gas[i].
 *
 * You have a car with an unlimited gas tank and it costs cost[i] of gas to travel from station i to its next station (i+1). You begin the journey with an empty tank at one of the gas stations.
 *
 * Return the starting gas station's index if you can travel around the circuit once, otherwise return -1.
 *
 * Note:
 * The solution is guaranteed to be unique.
 */
int canCompleteCircuit_134(int *gas, int gasSize, int *cost, int costSize);

#endif //LEETCODE_GAS_STATION_H

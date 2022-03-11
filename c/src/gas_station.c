#include "gas_station.h"

int canCompleteCircuit_134_1(int *gas, int gasSize, int *cost, int costSize) {
    int begin = 0;
    int tank = 0, total = 0;
    for (int i = 0; i < gasSize; ++i) {
        tank += gas[i] - cost[i];
        total += gas[i] - cost[i];
        if (tank < 0) {
            begin = i + 1;
            tank = 0;
        }
    }
    return total < 0 ? -1 : begin;
}

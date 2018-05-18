#include <gas_station.h>
#include <stddef.h>

int canCompleteCircuit_134(int *gas, int gasSize, int *cost, int costSize) {
    if (gas == NULL || gasSize < 1 || cost == NULL || costSize < 1 || gasSize != costSize) return -1;

    int begin = 0;
    int tank = 0, over = 0;
    for (int i = 0; i < gasSize; ++i) {
        tank += gas[i] - cost[i];
        over += gas[i] - cost[i];
        if (tank < 0) {
            begin = i + 1;
            tank = 0;
        }
    }
    if (over < 0) {
        begin = -1;
    }
    return begin;
}

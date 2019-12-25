#include "GasStation.h"
#include <cassert>

using namespace lcpp;

int Solution134_1::canCompleteCircuit(std::vector<int> &gas,
                                      std::vector<int> &cost) {
  std::vector<int>::size_type I, E = gas.size(), Start = 0;
  assert(E == cost.size());
  int Tank = 0, Total = 0;
  for (I = 0; I != E; ++I) {
    Tank += gas[I] - cost[I];
    Total += gas[I] - cost[I];
    if (Tank < 0) {
      Start = I + 1;
      Tank = 0;
    }
  }
  return Total >= 0 ? Start : -1;
}

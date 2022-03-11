#include "GasStation.h"
#include "gtest/gtest.h"
#include <string>

using namespace lcpp;

TEST(GasStation, Solution134_1) {
  auto S134_1 = Solution134_1();

  std::vector<int> Gas1{1, 2, 3, 4, 5}, Cost1{3, 4, 5, 1, 2};
  int const Expected1 = 3;
  EXPECT_EQ(Expected1, S134_1.canCompleteCircuit(Gas1, Cost1));

  std::vector<int> Gas2{2, 3, 4}, Cost2{3, 4, 3};
  int const Expected2 = -1;
  EXPECT_EQ(Expected2, S134_1.canCompleteCircuit(Gas2, Cost2));
}
#include "SubsetsII.h"
#include "gtest/gtest.h"

using namespace lcpp;

TEST(SubsetsII, Solution90_1) {
  std::vector<int> Nums{1, 2, 2};
  const std::vector<std::vector<int>> Expected{
      {},
      {1},
      {1, 2},
      {1, 2, 2},
      {2},
      {2, 2}
  };
  EXPECT_EQ(Expected, Solution90_1().subsetsWithDup(Nums));
}
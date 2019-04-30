#include "ProductOfArrayExceptSelf.h"
#include "gtest/gtest.h"

using namespace lcpp;

TEST(ProductOfArrayExceptSelf, Solution238_1) {
  std::vector<int> Nums{1, 2, 3, 4};
  const std::vector<int> Expected{24, 12, 8, 6};
  EXPECT_EQ(Expected, Solution238_1().productExceptSelf(Nums));
}
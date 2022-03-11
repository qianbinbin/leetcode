#include "Candy.h"
#include "gtest/gtest.h"

using namespace lcpp;

TEST(Candy, Solution135_1) {
  auto S135_1 = Solution135_1();

  std::vector<int> Ratings1{1, 0, 2};
  int const Expected1 = 5;
  EXPECT_EQ(Expected1, S135_1.candy(Ratings1));

  std::vector<int> Ratings2{1, 2, 2};
  int const Expected2 = 4;
  EXPECT_EQ(Expected2, S135_1.candy(Ratings2));
}
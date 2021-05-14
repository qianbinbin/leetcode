#include "JumpGameII.h"
#include "gtest/gtest.h"

using namespace lcpp;

TEST(JumpGameII, Solution45_1) {
  auto S45_1 = Solution45_1();

  std::vector<int> Nums1{2, 3, 1, 1, 4};
  int const Expected1 = 2;
  EXPECT_EQ(Expected1, S45_1.jump(Nums1));

  std::vector<int> Nums2{2, 3, 0, 1, 4};
  int const Expected2 = 2;
  EXPECT_EQ(Expected2, S45_1.jump(Nums2));
}

#include "JumpGame.h"
#include "gtest/gtest.h"

using namespace lcpp;

TEST(JumpGame, Solution55_1) {
  auto S55_1 = Solution55_1();

  std::vector<int> Nums1{2, 3, 1, 1, 4};
  EXPECT_TRUE(S55_1.canJump(Nums1));

  std::vector<int> Nums2{3, 2, 1, 0, 4};
  EXPECT_FALSE(S55_1.canJump(Nums2));
}

TEST(JumpGame, Solution55_2) {
  std::vector<int> Nums1{2, 3, 1, 1, 4};
  EXPECT_TRUE(Solution55_2().canJump(Nums1));

  std::vector<int> Nums2{3, 2, 1, 0, 4};
  EXPECT_FALSE(Solution55_2().canJump(Nums2));
}

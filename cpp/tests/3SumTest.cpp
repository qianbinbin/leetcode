#include "3Sum.h"
#include "gtest/gtest.h"

using namespace lcpp;

TEST(ThreeSum, Solution15_1) {
  auto S15_1 = Solution15_1();

  std::vector<int> Nums1{-1, 0, 1, 2, -1, -4};
  const std::vector<std::vector<int>> Expected1{{-1, -1, 2}, {-1, 0, 1}};
  EXPECT_EQ(Expected1, S15_1.threeSum(Nums1));

  std::vector<int> Nums2{};
  const std::vector<std::vector<int>> Expected2{};
  EXPECT_EQ(Expected2, S15_1.threeSum(Nums2));

  std::vector<int> Nums3{0};
  const std::vector<std::vector<int>> Expected3{};
  EXPECT_EQ(Expected3, S15_1.threeSum(Nums3));
}
#include "4Sum.h"
#include "gtest/gtest.h"

using namespace lcpp;

TEST(FourSum, Solution18_1) {
  auto S18_1 = Solution18_1();

  std::vector<int> Nums1{1, 0, -1, 0, -2, 2};
  int const Target1 = 0;
  std::vector<std::vector<int>> const Expected1{
      {-2, -1, 1, 2}, {-2, 0, 0, 2}, {-1, 0, 0, 1}};
  EXPECT_EQ(Expected1, S18_1.fourSum(Nums1, Target1));

  std::vector<int> Nums2;
  int const Target2 = 0;
  std::vector<std::vector<int>> const Expected2;
  EXPECT_EQ(Expected2, S18_1.fourSum(Nums2, Target2));
}

TEST(FourSum, Solution18_2) {
  auto S18_2 = Solution18_2();

  std::vector<int> Nums1{1, 0, -1, 0, -2, 2};
  int const Target1 = 0;
  std::vector<std::vector<int>> const Expected1{
      {-2, -1, 1, 2}, {-2, 0, 0, 2}, {-1, 0, 0, 1}};
  EXPECT_EQ(Expected1, S18_2.fourSum(Nums1, Target1));

  std::vector<int> Nums2;
  int const Target2 = 0;
  std::vector<std::vector<int>> const Expected2;
  EXPECT_EQ(Expected2, S18_2.fourSum(Nums2, Target2));
}

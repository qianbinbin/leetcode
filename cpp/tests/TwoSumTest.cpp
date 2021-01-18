#include "TwoSum.h"
#include "gtest/gtest.h"

using namespace lcpp;

TEST(TwoSum, Solution1_1) {
  auto S1_1 = Solution1_1();

  std::vector<int> Nums1{2, 7, 11, 15};
  const int Target1 = 9;
  const std::vector<int> Expected1{0, 1};
  EXPECT_EQ(Expected1, S1_1.twoSum(Nums1, Target1));

  std::vector<int> Nums2{3, 2, 4};
  const int Target2 = 6;
  const std::vector<int> Expected2{1, 2};
  EXPECT_EQ(Expected2, S1_1.twoSum(Nums2, Target2));

  std::vector<int> Nums3{3, 3};
  const int Target3 = 6;
  const std::vector<int> Expected3{0, 1};
  EXPECT_EQ(Expected3, S1_1.twoSum(Nums3, Target3));
}
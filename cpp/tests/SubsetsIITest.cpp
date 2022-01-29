#include "SubsetsII.h"
#include "gtest/gtest.h"

using namespace lcpp;

TEST(SubsetsII, Solution90_1) {
  auto S90_1 = Solution90_1();

  std::vector<int> Nums1{1, 2, 2};
  std::vector<std::vector<int>> Expected1{{},        {1}, {1, 2},
                                          {1, 2, 2}, {2}, {2, 2}};
  EXPECT_EQ(Expected1, S90_1.subsetsWithDup(Nums1));

  std::vector<int> Nums2{0};
  std::vector<std::vector<int>> Expected2{{}, {0}};
  EXPECT_EQ(Expected2, S90_1.subsetsWithDup(Nums2));
}
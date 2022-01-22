#include "SortColors.h"
#include "gtest/gtest.h"

using namespace lcpp;

TEST(SortColors, Solution75_1) {
  auto S75_1 = Solution75_1();

  std::vector<int> Nums1{2, 0, 2, 1, 1, 0};
  std::vector<int> const Expected1{0, 0, 1, 1, 2, 2};
  S75_1.sortColors(Nums1);
  EXPECT_EQ(Expected1, Nums1);

  std::vector<int> Nums2{2, 0, 1};
  std::vector<int> const Expected2{0, 1, 2};
  S75_1.sortColors(Nums2);
  EXPECT_EQ(Expected2, Nums2);
}

TEST(SortColors, Solution75_2) {
  auto S75_2 = Solution75_2();

  std::vector<int> Nums1{2, 0, 2, 1, 1, 0};
  std::vector<int> const Expected1{0, 0, 1, 1, 2, 2};
  S75_2.sortColors(Nums1);
  EXPECT_EQ(Expected1, Nums1);

  std::vector<int> Nums2{2, 0, 1};
  std::vector<int> const Expected2{0, 1, 2};
  S75_2.sortColors(Nums2);
  EXPECT_EQ(Expected2, Nums2);
}

#include "RemoveDuplicatesFromSortedArrayII.h"
#include "gtest/gtest.h"

using namespace lcpp;

TEST(RemoveDuplicatesFromSortedArrayII, Solution81_1) {
  std::vector<int> Nums1{1, 1, 1, 2, 2, 3};
  const int Size1 = 5;
  ASSERT_EQ(Size1, Solution80_1().removeDuplicates(Nums1));
  const std::vector<int> Expected1{1, 1, 2, 2, 3};
  EXPECT_EQ(Expected1, std::vector<int>(Nums1.begin(), Nums1.begin() + Size1));

  std::vector<int> Nums2{0, 0, 1, 1, 1, 1, 2, 3, 3};
  const int Size2 = 7;
  ASSERT_EQ(Size2, Solution80_1().removeDuplicates(Nums2));
  const std::vector<int> Expected2{0, 0, 1, 1, 2, 3, 3};
  EXPECT_EQ(Expected2, std::vector<int>(Nums2.begin(), Nums2.begin() + Size2));
}
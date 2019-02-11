#include "RemoveDuplicatesFromSortedArray.h"
#include "gtest/gtest.h"

using namespace lcpp;

TEST(RemoveDuplicatesFromSortedArray, Solution26_1) {
  std::vector<int> Nums1{1, 1, 2};
  const int Size1 = 2;
  ASSERT_EQ(Size1, Solution26_1().removeDuplicates(Nums1));
  const std::vector<int> Expected1{1, 2};
  EXPECT_EQ(Expected1, std::vector<int>(Nums1.begin(), Nums1.begin() + Size1));

  std::vector<int> Nums2{0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
  const int Size2 = 5;
  ASSERT_EQ(Size2, Solution26_1().removeDuplicates(Nums2));
  const std::vector<int> Expected2{0, 1, 2, 3, 4};
  EXPECT_EQ(Expected2, std::vector<int>(Nums2.begin(), Nums2.begin() + Size2));
}
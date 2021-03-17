#include "RemoveDuplicatesFromSortedArray.h"
#include "gtest/gtest.h"

using namespace lcpp;

TEST(RemoveDuplicatesFromSortedArray, Solution26_1) {
  auto S26_1 = Solution26_1();

  std::vector<int> Nums1{1, 1, 2};
  std::vector<int> const Expected1{1, 2};
  int const Size1 = S26_1.removeDuplicates(Nums1);
  EXPECT_EQ(Expected1, std::vector<int>(Nums1.begin(), Nums1.begin() + Size1));

  std::vector<int> Nums2{0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
  std::vector<int> const Expected2{0, 1, 2, 3, 4};
  int const Size2 = S26_1.removeDuplicates(Nums2);
  EXPECT_EQ(Expected2, std::vector<int>(Nums2.begin(), Nums2.begin() + Size2));
}
#include "RemoveDuplicatesFromSortedArrayII.h"
#include "gtest/gtest.h"

using namespace lcpp;

TEST(RemoveDuplicatesFromSortedArrayII, Solution81_1) {
  auto S80_1 = Solution80_1();

  std::vector<int> Nums1{1, 1, 1, 2, 2, 3};
  std::vector<int> const Expected1{1, 1, 2, 2, 3};
  int Size1 = S80_1.removeDuplicates(Nums1);
  EXPECT_EQ(Expected1, std::vector<int>(Nums1.begin(), Nums1.begin() + Size1));

  std::vector<int> Nums2{0, 0, 1, 1, 1, 1, 2, 3, 3};
  std::vector<int> const Expected2{0, 0, 1, 1, 2, 3, 3};
  int Size2 = S80_1.removeDuplicates(Nums2);
  EXPECT_EQ(Expected2, std::vector<int>(Nums2.begin(), Nums2.begin() + Size2));
}
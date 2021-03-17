#include "RemoveElement.h"
#include "gtest/gtest.h"

using namespace lcpp;

TEST(RemoveElement, Solution27_1) {
  auto S27_1 = Solution27_1();

  std::vector<int> Nums1{3, 2, 2, 3};
  int const Val1 = 3;
  std::vector<int> const Expected1{2, 2};
  int const Size1 = S27_1.removeElement(Nums1, Val1);
  ASSERT_EQ(Expected1.size(), Size1);
  EXPECT_EQ(Expected1, std::vector<int>(Nums1.begin(), Nums1.begin() + Size1));

  std::vector<int> Nums2{0, 1, 2, 2, 3, 0, 4, 2};
  int const Val2 = 2;
  std::vector<int> const Expected2{0, 1, 3, 0, 4};
  int Size2 = S27_1.removeElement(Nums2, Val2);
  ASSERT_EQ(Expected2.size(), Size2);
  EXPECT_EQ(Expected2, std::vector<int>(Nums2.begin(), Nums2.begin() + Size2));
}
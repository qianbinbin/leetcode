#include "RemoveElement.h"
#include "gtest/gtest.h"

using namespace lcpp;

TEST(RemoveElement, Solution27_1) {
  std::vector<int> Nums1{3, 2, 2, 3};
  int Val1 = 3;
  const int Size1 = 2;
  ASSERT_EQ(Size1, Solution27_1().removeElement(Nums1, Val1));
  const std::vector<int> Expected1{2, 2};
  EXPECT_EQ(Expected1, std::vector<int>(Nums1.begin(), Nums1.begin() + Size1));

  std::vector<int> Nums2{0, 1, 2, 2, 3, 0, 4, 2};
  int Val2 = 2;
  const int Size2 = 5;
  ASSERT_EQ(Size2, Solution27_1().removeElement(Nums2, Val2));
  const std::vector<int> Expected2{0, 1, 3, 0, 4};
  EXPECT_EQ(Expected2, std::vector<int>(Nums2.begin(), Nums2.begin() + Size2));
}
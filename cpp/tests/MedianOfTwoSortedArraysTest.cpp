#include "MedianOfTwoSortedArrays.h"
#include "gtest/gtest.h"

using namespace lcpp;

TEST(MedianOfTwoSortedArrays, Solution4_1) {
  auto S4_1 = Solution4_1();

  std::vector<int> Nums11{1, 3}, Nums12{2};
  const double Expected1 = 2;
  EXPECT_DOUBLE_EQ(Expected1, S4_1.findMedianSortedArrays(Nums11, Nums12));

  std::vector<int> Nums21{1, 2}, Nums22{3, 4};
  const double Expected2 = 2.5;
  EXPECT_DOUBLE_EQ(Expected2, S4_1.findMedianSortedArrays(Nums21, Nums22));

  std::vector<int> Nums31{0, 0}, Nums32{0, 0};
  const double Expected3 = 0;
  EXPECT_DOUBLE_EQ(Expected3, S4_1.findMedianSortedArrays(Nums31, Nums32));

  std::vector<int> Nums41{}, Nums42{1};
  const double Expected4 = 1;
  EXPECT_DOUBLE_EQ(Expected4, S4_1.findMedianSortedArrays(Nums41, Nums42));

  std::vector<int> Nums51{2}, Nums52{};
  const double Expected5 = 2;
  EXPECT_DOUBLE_EQ(Expected5, S4_1.findMedianSortedArrays(Nums51, Nums52));
}
#include "MergeSortedArray.h"
#include "gtest/gtest.h"

using namespace lcpp;

TEST(MergeSortedArray, Solution88_1) {
  auto S88_1 = Solution88_1();

  std::vector<int> Nums11{1, 2, 3, 0, 0, 0}, Nums12{2, 5, 6};
  int const M1 = 3, N1 = 3;
  std::vector<int> const Expected1{1, 2, 2, 3, 5, 6};
  S88_1.merge(Nums11, M1, Nums12, N1);
  EXPECT_EQ(Expected1, Nums11);

  std::vector<int> Nums21{1}, Nums22;
  int const M2 = 1, N2 = 0;
  std::vector<int> const Expected2{1};
  S88_1.merge(Nums21, M2, Nums22, N2);
  EXPECT_EQ(Expected2, Nums21);

  std::vector<int> Nums31{0}, Nums32{1};
  int const M3 = 0, N3 = 1;
  std::vector<int> const Expected3{1};
  S88_1.merge(Nums31, M3, Nums32, N3);
  EXPECT_EQ(Expected3, Nums31);
}
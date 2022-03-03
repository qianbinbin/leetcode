#include "LongestConsecutiveSequence.h"
#include "gtest/gtest.h"

using namespace lcpp;

TEST(LongestConsecutiveSequence, Solution128_1) {
  auto S128_1 = Solution128_1();

  std::vector<int> Nums1{100, 4, 200, 1, 3, 2};
  int const Expected1 = 4;
  EXPECT_EQ(Expected1, S128_1.longestConsecutive(Nums1));

  std::vector<int> Nums2{0, 3, 7, 2, 5, 8, 4, 6, 0, 1};
  int const Expected2 = 9;
  EXPECT_EQ(Expected2, S128_1.longestConsecutive(Nums2));
}

TEST(LongestConsecutiveSequence, Solution128_2) {
  auto S128_2 = Solution128_2();

  std::vector<int> Nums1{100, 4, 200, 1, 3, 2};
  int const Expected1 = 4;
  EXPECT_EQ(Expected1, S128_2.longestConsecutive(Nums1));

  std::vector<int> Nums2{0, 3, 7, 2, 5, 8, 4, 6, 0, 1};
  int const Expected2 = 9;
  EXPECT_EQ(Expected2, S128_2.longestConsecutive(Nums2));
}

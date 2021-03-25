#include "SearchInsertPosition.h"
#include "gtest/gtest.h"

using namespace lcpp;

TEST(SearchInsertPosition, Solution35_1) {
  auto S35_1 = Solution35_1();

  std::vector<int> Nums1{1, 3, 5, 6};
  int const Target1 = 5;
  int const Expected1 = 2;
  EXPECT_EQ(Expected1, S35_1.searchInsert(Nums1, Target1));

  std::vector<int> Nums2{1, 3, 5, 6};
  int const Target2 = 2;
  int const Expected2 = 1;
  EXPECT_EQ(Expected2, S35_1.searchInsert(Nums2, Target2));

  std::vector<int> Nums3{1, 3, 5, 6};
  int const Target3 = 7;
  int const Expected3 = 4;
  EXPECT_EQ(Expected3, S35_1.searchInsert(Nums3, Target3));

  std::vector<int> Nums4{1, 3, 5, 6};
  int const Target4 = 0;
  int const Expected4 = 0;
  EXPECT_EQ(Expected4, S35_1.searchInsert(Nums4, Target4));

  std::vector<int> Nums5{1};
  int const Target5 = 0;
  int const Expected5 = 0;
  EXPECT_EQ(Expected5, S35_1.searchInsert(Nums5, Target5));
}
#include "InsertInterval.h"
#include "gtest/gtest.h"

using namespace lcpp;

TEST(InsertInterval, Solution57_1) {
  auto S57_1 = Solution57_1();

  std::vector<std::vector<int>> Intervals1{{1, 3}, {6, 9}};
  std::vector<int> NewInterval1{2, 5};
  const std::vector<std::vector<int>> Expected1{{1, 5}, {6, 9}};
  EXPECT_EQ(Expected1, S57_1.insert(Intervals1, NewInterval1));

  std::vector<std::vector<int>> Intervals2{
      {1, 2}, {3, 5}, {6, 7}, {8, 10}, {12, 16}};
  std::vector<int> NewInterval2{4, 8};
  const std::vector<std::vector<int>> Expected2{{1, 2}, {3, 10}, {12, 16}};
  EXPECT_EQ(Expected2, S57_1.insert(Intervals2, NewInterval2));

  std::vector<std::vector<int>> Intervals3;
  std::vector<int> NewInterval3{5, 7};
  const std::vector<std::vector<int>> Expected3{{5, 7}};
  EXPECT_EQ(Expected3, S57_1.insert(Intervals3, NewInterval3));

  std::vector<std::vector<int>> Intervals4{{1, 5}};
  std::vector<int> NewInterval4{2, 3};
  const std::vector<std::vector<int>> Expected4{{1, 5}};
  EXPECT_EQ(Expected4, S57_1.insert(Intervals4, NewInterval4));

  std::vector<std::vector<int>> Intervals5{{1, 5}};
  std::vector<int> NewInterval5{2, 7};
  const std::vector<std::vector<int>> Expected5{{1, 7}};
  EXPECT_EQ(Expected5, S57_1.insert(Intervals5, NewInterval5));
}
#include "ReverseNodesInKGroup.h"
#include "gtest/gtest.h"

using namespace lcpp;

TEST(ReverseNodesInKGroup, Solution25_1) {
  auto S25_1 = Solution25_1();

  auto Head1 = newLinkedList({1, 2, 3, 4, 5});
  int const K1 = 2;
  auto Expected1 = newLinkedList({2, 1, 4, 3, 5});
  auto Actual1 = S25_1.reverseKGroup(Head1, K1);
  EXPECT_EQ(*Expected1, *Actual1);
  deleteLinkedList(Expected1);
  deleteLinkedList(Actual1);

  auto Head2 = newLinkedList({1, 2, 3, 4, 5});
  int const K2 = 3;
  auto Expected2 = newLinkedList({3, 2, 1, 4, 5});
  auto Actual2 = S25_1.reverseKGroup(Head2, K2);
  EXPECT_EQ(*Expected2, *Actual2);
  deleteLinkedList(Expected2);
  deleteLinkedList(Actual2);

  auto Head3 = newLinkedList({1, 2, 3, 4, 5});
  int const K3 = 1;
  auto Expected3 = newLinkedList({1, 2, 3, 4, 5});
  auto Actual3 = S25_1.reverseKGroup(Head3, K3);
  EXPECT_EQ(*Expected3, *Actual3);
  deleteLinkedList(Expected3);
  deleteLinkedList(Actual3);

  auto Head4 = newLinkedList({1});
  int const K4 = 1;
  auto Expected4 = newLinkedList({1});
  auto Actual4 = S25_1.reverseKGroup(Head4, K4);
  EXPECT_EQ(*Expected4, *Actual4);
  deleteLinkedList(Expected4);
  deleteLinkedList(Actual4);
}
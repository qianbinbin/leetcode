#include "FlattenBinaryTreeToLinkedList.h"
#include "gtest/gtest.h"

using namespace lcpp;

TEST(FlattenBinaryTreeToLinkedList, Solution114_1) {
  auto S114_1 = Solution114_1();

  auto Root1 = newTree({1, 2, 5, 3, 4, NTNode, 6});
  auto Expected1 =
      newTree({1, NTNode, 2, NTNode, 3, NTNode, 4, NTNode, 5, NTNode, 6});
  S114_1.flatten(Root1);
  EXPECT_EQ(*Expected1, *Root1);
  deleteTree(Root1);
  deleteTree(Expected1);

  auto Root2 = newTree({});
  auto Expected2 = newTree({});
  S114_1.flatten(Root2);
  EXPECT_EQ(*Expected2, *Root2);
  deleteTree(Root2);
  deleteTree(Expected2);

  auto Root3 = newTree({0});
  auto Expected3 = newTree({0});
  S114_1.flatten(Root3);
  EXPECT_EQ(*Expected3, *Root3);
  deleteTree(Root3);
  deleteTree(Expected3);
}

TEST(FlattenBinaryTreeToLinkedList, Solution114_2) {
  auto S114_2 = Solution114_2();

  auto Root1 = newTree({1, 2, 5, 3, 4, NTNode, 6});
  auto Expected1 =
      newTree({1, NTNode, 2, NTNode, 3, NTNode, 4, NTNode, 5, NTNode, 6});
  S114_2.flatten(Root1);
  EXPECT_EQ(*Expected1, *Root1);
  deleteTree(Root1);
  deleteTree(Expected1);

  auto Root2 = newTree({});
  auto Expected2 = newTree({});
  S114_2.flatten(Root2);
  EXPECT_EQ(*Expected2, *Root2);
  deleteTree(Root2);
  deleteTree(Expected2);

  auto Root3 = newTree({0});
  auto Expected3 = newTree({0});
  S114_2.flatten(Root3);
  EXPECT_EQ(*Expected3, *Root3);
  deleteTree(Root3);
  deleteTree(Expected3);
}

#include <gtest/gtest.h>

extern "C" {
#include "same_tree.h"
}

TEST(same_tree_test, isSameTree_100_1) {
    int nums11[] = {1, 2, 3};
    struct TreeNode *tree11 = tree_create(nums11, sizeof(nums11) / sizeof(nums11[0]));
    int nums12[] = {1, 2, 3};
    struct TreeNode *tree12 = tree_create(nums12, sizeof(nums12) / sizeof(nums12[0]));
    EXPECT_TRUE(isSameTree_100_1(tree11, tree12));
    tree_free(tree11);
    tree_free(tree12);

    int nums21[] = {1, 2};
    struct TreeNode *tree21 = tree_create(nums21, sizeof(nums21) / sizeof(nums21[0]));
    int nums22[] = {1, NTNODE, 2};
    struct TreeNode *tree22 = tree_create(nums22, sizeof(nums22) / sizeof(nums22[0]));
    EXPECT_FALSE(isSameTree_100_1(tree21, tree22));
    tree_free(tree21);
    tree_free(tree22);

    int nums31[] = {1, 2, 1};
    struct TreeNode *tree31 = tree_create(nums31, sizeof(nums31) / sizeof(nums31[0]));
    int nums32[] = {1, 1, 2};
    struct TreeNode *tree32 = tree_create(nums32, sizeof(nums32) / sizeof(nums32[0]));
    EXPECT_FALSE(isSameTree_100_1(tree31, tree32));
    tree_free(tree31);
    tree_free(tree32);
}

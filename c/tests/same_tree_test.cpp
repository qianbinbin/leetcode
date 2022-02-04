#include <gtest/gtest.h>

extern "C" {
#include "same_tree.h"
}

TEST(same_tree_test, isSameTree_100_1) {
    int nums11[] = {1, 2, 3};
    struct TreeNode *p1 = tree_create(nums11,
                                      sizeof(nums11) / sizeof(nums11[0]));
    int nums12[] = {1, 2, 3};
    struct TreeNode *q1 = tree_create(nums12,
                                      sizeof(nums12) / sizeof(nums12[0]));
    EXPECT_TRUE(isSameTree_100_1(p1, q1));
    tree_free(p1);
    tree_free(q1);

    int nums21[] = {1, 2};
    struct TreeNode *p2 = tree_create(nums21,
                                      sizeof(nums21) / sizeof(nums21[0]));
    int nums22[] = {1, NTNODE, 2};
    struct TreeNode *q2 = tree_create(nums22,
                                      sizeof(nums22) / sizeof(nums22[0]));
    EXPECT_FALSE(isSameTree_100_1(p2, q2));
    tree_free(p2);
    tree_free(q2);

    int nums31[] = {1, 2, 1};
    struct TreeNode *p3 = tree_create(nums31,
                                      sizeof(nums31) / sizeof(nums31[0]));
    int nums32[] = {1, 1, 2};
    struct TreeNode *q3 = tree_create(nums32,
                                      sizeof(nums32) / sizeof(nums32[0]));
    EXPECT_FALSE(isSameTree_100_1(p3, q3));
    tree_free(p3);
    tree_free(q3);
}

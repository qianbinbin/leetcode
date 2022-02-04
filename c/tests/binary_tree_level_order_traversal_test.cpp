#include <gtest/gtest.h>

extern "C" {
#include "binary_tree_level_order_traversal.h"
}

TEST(binary_tree_level_order_traversal_test, levelOrder_102_1) {
    int nums1[] = {3, 9, 20, NTNODE, NTNODE, 15, 7};
    struct TreeNode *root1 = tree_create(nums1,
                                         sizeof(nums1) / sizeof(nums1[0]));
    int returnSize1 = 0;
    int *returnColumnSizes1 = NULL;
    std::vector<std::vector<int>> expected1{{3},
                                            {9,  20},
                                            {15, 7}};
    int **actual1 = levelOrder_102_1(root1, &returnSize1, &returnColumnSizes1);
    ASSERT_EQ(expected1.size(), returnSize1);
    for (int i = 0; i < returnSize1; ++i) {
        EXPECT_EQ(expected1[i], std::vector<int>(actual1[i], actual1[i] +
                                                             returnColumnSizes1[i]));
        free(actual1[i]);
    }
    free(actual1);
    free(returnColumnSizes1);
    tree_free(root1);

    int nums2[] = {1};
    struct TreeNode *root2 = tree_create(nums2,
                                         sizeof(nums2) / sizeof(nums2[0]));
    int returnSize2 = 0;
    int *returnColumnSizes2 = NULL;
    std::vector<std::vector<int>> expected2{{1}};
    int **actual2 = levelOrder_102_1(root2, &returnSize2, &returnColumnSizes2);
    ASSERT_EQ(expected2.size(), returnSize2);
    for (int i = 0; i < returnSize2; ++i) {
        EXPECT_EQ(expected2[i], std::vector<int>(actual2[i], actual2[i] +
                                                             returnColumnSizes2[i]));
        free(actual2[i]);
    }
    free(actual2);
    free(returnColumnSizes2);
    tree_free(root2);

    struct TreeNode *root3 = NULL;
    int returnSize3 = 0;
    int *returnColumnSizes3 = NULL;
    std::vector<std::vector<int>> expected3{};
    int **actual3 = levelOrder_102_1(root3, &returnSize3, &returnColumnSizes3);
    ASSERT_EQ(expected3.size(), returnSize3);
    for (int i = 0; i < returnSize3; ++i) {
        EXPECT_EQ(expected3[i], std::vector<int>(actual3[i], actual3[i] +
                                                             returnColumnSizes3[i]));
        free(actual3[i]);
    }
    free(actual3);
    free(returnColumnSizes3);
    tree_free(root3);
}

TEST(binary_tree_level_order_traversal_test, levelOrder_102_2) {
    int nums1[] = {3, 9, 20, NTNODE, NTNODE, 15, 7};
    struct TreeNode *root1 = tree_create(nums1,
                                         sizeof(nums1) / sizeof(nums1[0]));
    int returnSize1 = 0;
    int *returnColumnSizes1 = NULL;
    std::vector<std::vector<int>> expected1{{3},
                                            {9,  20},
                                            {15, 7}};
    int **actual1 = levelOrder_102_2(root1, &returnSize1, &returnColumnSizes1);
    ASSERT_EQ(expected1.size(), returnSize1);
    for (int i = 0; i < returnSize1; ++i) {
        EXPECT_EQ(expected1[i], std::vector<int>(actual1[i], actual1[i] +
                                                             returnColumnSizes1[i]));
        free(actual1[i]);
    }
    free(actual1);
    free(returnColumnSizes1);
    tree_free(root1);

    int nums2[] = {1};
    struct TreeNode *root2 = tree_create(nums2,
                                         sizeof(nums2) / sizeof(nums2[0]));
    int returnSize2 = 0;
    int *returnColumnSizes2 = NULL;
    std::vector<std::vector<int>> expected2{{1}};
    int **actual2 = levelOrder_102_2(root2, &returnSize2, &returnColumnSizes2);
    ASSERT_EQ(expected2.size(), returnSize2);
    for (int i = 0; i < returnSize2; ++i) {
        EXPECT_EQ(expected2[i], std::vector<int>(actual2[i], actual2[i] +
                                                             returnColumnSizes2[i]));
        free(actual2[i]);
    }
    free(actual2);
    free(returnColumnSizes2);
    tree_free(root2);

    struct TreeNode *root3 = NULL;
    int returnSize3 = 0;
    int *returnColumnSizes3 = NULL;
    std::vector<std::vector<int>> expected3{};
    int **actual3 = levelOrder_102_2(root3, &returnSize3, &returnColumnSizes3);
    ASSERT_EQ(expected3.size(), returnSize3);
    for (int i = 0; i < returnSize3; ++i) {
        EXPECT_EQ(expected3[i], std::vector<int>(actual3[i], actual3[i] +
                                                             returnColumnSizes3[i]));
        free(actual3[i]);
    }
    free(actual3);
    free(returnColumnSizes3);
    tree_free(root3);
}

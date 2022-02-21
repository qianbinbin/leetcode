#include <gtest/gtest.h>

extern "C" {
#include "path_sum_ii.h"
}

TEST(path_sum_ii_test, pathSum_113_1) {
    int nums1[] = {5, 4, 8, 11, NTNODE, 13, 4, 7, 2, NTNODE, NTNODE, NTNODE,
                   NTNODE, 5, 1};
    struct TreeNode *root1 = tree_create(nums1,
                                         sizeof(nums1) / sizeof(nums1[0]));
    int const targetSum1 = 22;
    int returnSize1 = 0;
    int *returnColumnSizes1 = NULL;
    int **actual1 = pathSum_113_1(root1, targetSum1, &returnSize1,
                                  &returnColumnSizes1);
    std::vector<std::vector<int>> expected1{{5, 4, 11, 2},
                                            {5, 8, 4,  5}};
    ASSERT_EQ(expected1.size(), returnSize1);
    for (int i = 0; i < returnSize1; ++i) {
        EXPECT_EQ(expected1[i], std::vector<int>(actual1[i], actual1[i] +
                                                             returnColumnSizes1[i]));
        free(actual1[i]);
    }
    free(returnColumnSizes1);
    tree_free(root1);

    int nums2[] = {1, 2, 3};
    struct TreeNode *root2 = tree_create(nums2,
                                         sizeof(nums2) / sizeof(nums2[0]));
    int const targetSum2 = 5;
    int returnSize2 = 0;
    int *returnColumnSizes2 = NULL;
    int **actual2 = pathSum_113_1(root2, targetSum2, &returnSize2,
                                  &returnColumnSizes2);
    std::vector<std::vector<int>> expected2;
    ASSERT_EQ(expected2.size(), returnSize2);
    for (int i = 0; i < returnSize2; ++i) {
        EXPECT_EQ(expected2[i], std::vector<int>(actual2[i], actual2[i] +
                                                             returnColumnSizes2[i]));
        free(actual2[i]);
    }
    free(returnColumnSizes2);
    tree_free(root2);


    int nums3[] = {1, 2};
    struct TreeNode *root3 = tree_create(nums3,
                                         sizeof(nums3) / sizeof(nums3[0]));
    int const targetSum3 = 0;
    int returnSize3 = 0;
    int *returnColumnSizes3 = NULL;
    int **actual3 = pathSum_113_1(root3, targetSum3, &returnSize3,
                                  &returnColumnSizes3);
    std::vector<std::vector<int>> expected3;
    ASSERT_EQ(expected3.size(), returnSize3);
    for (int i = 0; i < returnSize3; ++i) {
        EXPECT_EQ(expected3[i], std::vector<int>(actual3[i], actual3[i] +
                                                             returnColumnSizes3[i]));
        free(actual3[i]);
    }
    free(returnColumnSizes3);
    tree_free(root3);
}

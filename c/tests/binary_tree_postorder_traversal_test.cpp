#include <gtest/gtest.h>

extern "C" {
#include "binary_tree_postorder_traversal.h"
}

#define ARR_SIZE(a) (sizeof(a) / sizeof((a)[0]))

TEST(binary_tree_postorder_traversal_test, postorderTraversal_145_1) {
    int nums1[] = {1, NTNODE, 2, NTNODE, NTNODE, 3};
    struct TreeNode *root1 = tree_create(nums1, ARR_SIZE(nums1));
    int returnSize1 = 0;
    std::vector<int> expected1{3, 2, 1};
    int *actual1 = postorderTraversal_145_1(root1, &returnSize1);
    EXPECT_EQ(expected1, std::vector<int>(actual1, actual1 + returnSize1));
    free(actual1);
    tree_free(root1);

    struct TreeNode *root2 = NULL;
    int returnSize2 = 0;
    std::vector<int> expected2;
    int *actual2 = postorderTraversal_145_1(root2, &returnSize2);
    EXPECT_EQ(expected2, std::vector<int>(actual2, actual2 + returnSize2));
    free(actual2);
    tree_free(root2);

    int nums3[] = {1};
    struct TreeNode *root3 = tree_create(nums3, ARR_SIZE(nums3));
    int returnSize3 = 0;
    std::vector<int> expected3{1};
    int *actual3 = postorderTraversal_145_1(root3, &returnSize3);
    EXPECT_EQ(expected3, std::vector<int>(actual3, actual3 + returnSize3));
    free(actual3);
    tree_free(root3);
}

TEST(binary_tree_postorder_traversal_test, postorderTraversal_145_2) {
    int nums1[] = {1, NTNODE, 2, NTNODE, NTNODE, 3};
    struct TreeNode *root1 = tree_create(nums1, ARR_SIZE(nums1));
    int returnSize1 = 0;
    std::vector<int> expected1{3, 2, 1};
    int *actual1 = postorderTraversal_145_2(root1, &returnSize1);
    EXPECT_EQ(expected1, std::vector<int>(actual1, actual1 + returnSize1));
    free(actual1);
    tree_free(root1);

    struct TreeNode *root2 = NULL;
    int returnSize2 = 0;
    std::vector<int> expected2;
    int *actual2 = postorderTraversal_145_2(root2, &returnSize2);
    EXPECT_EQ(expected2, std::vector<int>(actual2, actual2 + returnSize2));
    free(actual2);
    tree_free(root2);

    int nums3[] = {1};
    struct TreeNode *root3 = tree_create(nums3, ARR_SIZE(nums3));
    int returnSize3 = 0;
    std::vector<int> expected3{1};
    int *actual3 = postorderTraversal_145_2(root3, &returnSize3);
    EXPECT_EQ(expected3, std::vector<int>(actual3, actual3 + returnSize3));
    free(actual3);
    tree_free(root3);
}

TEST(binary_tree_postorder_traversal_test, postorderTraversal_145_3) {
    int nums1[] = {1, NTNODE, 2, NTNODE, NTNODE, 3};
    struct TreeNode *root1 = tree_create(nums1, ARR_SIZE(nums1));
    int returnSize1 = 0;
    std::vector<int> expected1{3, 2, 1};
    int *actual1 = postorderTraversal_145_3(root1, &returnSize1);
    EXPECT_EQ(expected1, std::vector<int>(actual1, actual1 + returnSize1));
    free(actual1);
    tree_free(root1);

    struct TreeNode *root2 = NULL;
    int returnSize2 = 0;
    std::vector<int> expected2;
    int *actual2 = postorderTraversal_145_3(root2, &returnSize2);
    EXPECT_EQ(expected2, std::vector<int>(actual2, actual2 + returnSize2));
    free(actual2);
    tree_free(root2);

    int nums3[] = {1};
    struct TreeNode *root3 = tree_create(nums3, ARR_SIZE(nums3));
    int returnSize3 = 0;
    std::vector<int> expected3{1};
    int *actual3 = postorderTraversal_145_3(root3, &returnSize3);
    EXPECT_EQ(expected3, std::vector<int>(actual3, actual3 + returnSize3));
    free(actual3);
    tree_free(root3);
}
